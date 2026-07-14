#!/usr/bin/env python3
import csv
import re
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LOG_ROOT = Path('/tmp/nmsis-f32-failed-result-compare')
SIM_LOG_DIR = LOG_ROOT / 'sim'
HOST_LOG_DIR = LOG_ROOT / 'host'
HOST_BIN_DIR = LOG_ROOT / 'host-bin'
RESULT_CSV = ROOT / 'manifests/f32_failed_result_compare.csv'
RESULT_MD = ROOT / 'manifests/F32_FAILED_RESULT_COMPARE.md'
SUMMARY_CSV = ROOT / 'manifests/f32_candidate_run_summary.csv'

HELPER = """
static uint32_t zircon_result_hash_combine(uint32_t hash, const void *data, uint32_t length)
{
    const uint8_t *bytes = (const uint8_t *)data;

    for (uint32_t i = 0; i < length; i++) {
        hash ^= bytes[i];
        hash *= 16777619u;
    }

    return hash;
}

static void zircon_result_zero_f32(float32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++) {
        data[i] = 0.0f;
    }
}
"""


def load_cases():
    rows = []
    with SUMMARY_CSV.open(newline='') as f:
        for row in csv.DictReader(f):
            if row['system'] == 'benchmark' and row['result'] != 'PASS' and row['function'].endswith('_f32'):
                rows.append(row)
    return rows


def find_function_body(text, function):
    m = re.search(r'void\s+' + re.escape(function) + r'\s*\([^)]*\)\s*\{', text)
    if not m:
        return None
    start = m.end() - 1
    depth = 0
    for i in range(start, len(text)):
        ch = text[i]
        if ch == '{':
            depth += 1
        elif ch == '}':
            depth -= 1
            if depth == 0:
                return start, i + 1
    return None


def split_declarators(decl):
    parts = []
    cur = []
    depth = 0
    for ch in decl:
        if ch == ',' and depth == 0:
            parts.append(''.join(cur).strip())
            cur = []
            continue
        cur.append(ch)
        if ch in '([{':
            depth += 1
        elif ch in ')]}':
            depth -= 1
    if cur:
        parts.append(''.join(cur).strip())
    return parts


def declarator_name(part):
    part = part.split('=')[0].strip()
    part = part.replace('*', ' ')
    m = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^;]+\])?\s*$', part)
    return m.group(1) if m else None


def collect_local_items(body_before_bench_end):
    arrays = []
    scalars = []
    for m in re.finditer(r'\b(float32_t|uint32_t|int32_t|riscv_status|int)\s+([^;]+);', body_before_bench_end):
        typ, rest = m.group(1), m.group(2)
        for part in split_declarators(rest):
            name = declarator_name(part)
            if not name:
                continue
            if '[' in part and typ == 'float32_t':
                if name not in arrays:
                    arrays.append(name)
            else:
                lower = name.lower()
                if typ == 'float32_t' or any(key in lower for key in ['output', 'result', 'index', 'status', 'err']):
                    if name != 'i' and name not in scalars:
                        scalars.append(name)
    return arrays, scalars


def collect_testdata_arrays(text):
    m = re.search(r'#include\s+"(TestData/[^"]+test_data\.h)"', text)
    if not m:
        return []
    header = ROOT / 'vendor/NMSIS/DSP/Benchmark' / m.group(1)
    if not header.exists():
        return []
    htext = header.read_text(errors='ignore')
    arrays = []
    for am in re.finditer(r'\b(?:static\s+)?(?:const\s+)?(?:float32_t|uint32_t|int32_t)\s+([A-Za-z_]\w*)\s*\[[^;]+\]\s*(?:=\s*\{[^;]*\})?\s*;', htext, re.S):
        name = am.group(1)
        if name not in arrays:
            arrays.append(name)
    return arrays


def instrument_case(row):
    rel = row['path']
    function = row['function']
    path = ROOT / rel
    text = path.read_text(errors='ignore')
    if '@@RESULT@@' in text:
        return False
    body_span = find_function_body(text, function)
    if not body_span:
        raise RuntimeError(f'cannot find function {function} in {rel}')
    bstart, bend = body_span
    body = text[bstart:bend]
    bench = re.search(r'BENCH_END\s*\([^;]+;\s*', body)
    if not bench:
        raise RuntimeError(f'cannot find BENCH_END in {rel}')
    before = body[:bench.start()]
    local_arrays, local_scalars = collect_local_items(before)
    start_match = re.search(r'BENCH_START\s*\([^;]+;\s*', body)
    global_arrays = collect_testdata_arrays(text)

    items = []
    for name in local_arrays + global_arrays:
        if name not in items:
            items.append(name)
    scalar_items = []
    for name in local_scalars:
        if name not in scalar_items:
            scalar_items.append(name)

    lines = ['', '    uint32_t __zr_hash = 2166136261u;']
    for name in items:
        lines.append(f'    __zr_hash = zircon_result_hash_combine(__zr_hash, {name}, (uint32_t)sizeof({name}));')
    for name in scalar_items:
        lines.append(f'    __zr_hash = zircon_result_hash_combine(__zr_hash, &{name}, (uint32_t)sizeof({name}));')
    if len(lines) == 2:
        lines.append('    __zr_hash = zircon_result_hash_combine(__zr_hash, &__zr_hash, (uint32_t)sizeof(__zr_hash));')
    lines.extend([
        f'    printf("@@RESULT@@ case={function} hash=0x%08x\\n", (unsigned int)__zr_hash);',
        '',
    ])
    insertion = '\n'.join(lines)
    zero_insertion = ''
    if start_match and local_arrays:
        zero_lines = ['']
        for name in local_arrays:
            zero_lines.append(f'    zircon_result_zero_f32({name}, (uint32_t)(sizeof({name}) / sizeof({name}[0])));')
        zero_lines.append('')
        zero_insertion = '\n'.join(zero_lines)
    if zero_insertion:
        body = body[:start_match.start()] + zero_insertion + body[start_match.start():]
        bench = re.search(r'BENCH_END\s*\([^;]+;\s*', body)
    body2 = body[:bench.end()] + insertion + body[bench.end():]
    text2 = text[:bstart] + body2 + text[bend:]
    if 'static uint32_t zircon_result_hash_combine' not in text2:
        text2 = text2.replace('BENCH_DECLARE_VAR();\n', 'BENCH_DECLARE_VAR();\n' + HELPER + '\n', 1)
    path.write_text(text2)
    return True


def parse_sources(suite, function):
    mk = ROOT / f'generated/benchmark/{suite}/cases/{function}/sources.mk'
    if not mk.exists():
        raise RuntimeError(f'missing {mk}')
    sources = []
    active = False
    for line in mk.read_text().splitlines():
        stripped = line.strip()
        if stripped.startswith('TEST_SRCS'):
            active = True
            continue
        if active:
            if not stripped:
                continue
            src = stripped.rstrip('\\').strip()
            if src:
                sources.append(src)
    return sources


def run_cmd(cmd, log_path, timeout=180):
    log_path.parent.mkdir(parents=True, exist_ok=True)
    with log_path.open('w') as log:
        log.write('$ ' + ' '.join(shlex.quote(str(c)) for c in cmd) + '\n')
        log.flush()
        proc = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, timeout=timeout, text=True)
    return proc.returncode


def result_lines(log_path):
    if not log_path.exists():
        return ''
    lines = []
    for line in log_path.read_text(errors='ignore').splitlines():
        if '@@RESULT@@' in line:
            lines.append(line.strip())
    return ' | '.join(lines)


def host_compile_and_run(row):
    suite = row['suite']
    function = row['function']
    try:
        sources = parse_sources(suite, function)
    except Exception as e:
        log = HOST_LOG_DIR / f'{suite}__{function}.sources.log'
        log.parent.mkdir(parents=True, exist_ok=True)
        log.write_text(str(e))
        return 1, '', log, 'host_sources_missing'
    c_sources = [s for s in sources if s.endswith('.c') and s != 'port/src/compat_runtime.c']
    bin_path = HOST_BIN_DIR / function
    compile_log = HOST_LOG_DIR / f'{suite}__{function}.compile.log'
    run_log = HOST_LOG_DIR / f'{suite}__{function}.run.log'
    cmd = ['gcc', '-std=gnu99', '-O2', '-Wall', '-Wextra', '-Wno-unused-function', '-Wno-unused-variable', '-Wno-unused-parameter']
    cmd += ['-iquote', str(ROOT / 'port/include')]
    for inc in [
        'vendor/NMSIS/DSP/Include',
        'vendor/NMSIS/DSP/PrivateInclude',
        'vendor/NMSIS/DSP/Benchmark',
        f'vendor/NMSIS/DSP/Benchmark/{suite}',
    ]:
        cmd += ['-I', str(ROOT / inc)]
    cmd += ['-o', str(bin_path)]
    cmd += [str(ROOT / src) for src in c_sources]
    cmd += ['-lm']
    rc = run_cmd(cmd, compile_log, timeout=120)
    if rc != 0:
        return rc, '', compile_log, 'host_compile_failed'
    rc = run_cmd([str(bin_path)], run_log, timeout=120)
    if rc != 0:
        return rc, result_lines(run_log), run_log, 'host_run_failed'
    return rc, result_lines(run_log), run_log, ''


def sim_run(row):
    suite = row['suite']
    function = row['function']
    log = SIM_LOG_DIR / f'{suite}__{function}.log'
    cmd = [
        'make', '-C', str(ROOT),
        'TEST_SYSTEM=benchmark',
        f'SUITE={suite}',
        f'TEST_CASE={function}',
        'USE_SIMULATOR_ONLY_MODE=1',
        'run',
    ]
    rc = run_cmd(cmd, log, timeout=240)
    if rc != 0:
        return rc, result_lines(log), log, 'sim_run_failed'
    return rc, result_lines(log), log, ''


def write_reports(results):
    RESULT_CSV.parent.mkdir(parents=True, exist_ok=True)
    with RESULT_CSV.open('w', newline='') as f:
        fields = ['suite', 'function', 'path', 'status', 'sim_result', 'host_result', 'sim_log', 'host_log', 'note']
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        for r in results:
            w.writerow({k: r.get(k, '') for k in fields})
    total = len(results)
    matched = sum(1 for r in results if r['status'] == 'MATCH')
    mismatched = sum(1 for r in results if r['status'] == 'MISMATCH')
    failed = total - matched - mismatched
    lines = [
        '# F32 Failed Result Compare',
        '',
        f'- Total cases: {total}',
        f'- Match: {matched}',
        f'- Mismatch: {mismatched}',
        f'- Failed/incomplete: {failed}',
        f'- CSV: `manifests/{RESULT_CSV.name}`',
        f'- Logs: `{LOG_ROOT}`',
        '',
        '## Mismatches And Failures',
        '',
    ]
    rows = [r for r in results if r['status'] != 'MATCH']
    if not rows:
        lines.append('No mismatches or run failures were observed.')
    else:
        lines.append('| Suite | Function | Status | Sim Result | Host Result | Note |')
        lines.append('| --- | --- | --- | --- | --- | --- |')
        for r in rows:
            lines.append('| {suite} | `{function}` | {status} | `{sim}` | `{host}` | {note} |'.format(
                suite=r['suite'], function=r['function'], status=r['status'],
                sim=(r.get('sim_result') or '').replace('|', '\\|'),
                host=(r.get('host_result') or '').replace('|', '\\|'),
                note=r.get('note', ''),
            ))
    RESULT_MD.write_text('\n'.join(lines) + '\n')


def main():
    LOG_ROOT.mkdir(parents=True, exist_ok=True)
    SIM_LOG_DIR.mkdir(parents=True, exist_ok=True)
    HOST_LOG_DIR.mkdir(parents=True, exist_ok=True)
    HOST_BIN_DIR.mkdir(parents=True, exist_ok=True)
    rows = load_cases()
    changed = 0
    for row in rows:
        if instrument_case(row):
            changed += 1
    print(f'instrumented {changed} files; total failed f32 cases {len(rows)}')
    results = []
    for idx, row in enumerate(rows, 1):
        suite = row['suite']
        function = row['function']
        print(f'[{idx}/{len(rows)}] {suite}/{function}', flush=True)
        sim_rc, sim_result, sim_log, sim_note = sim_run(row)
        host_rc, host_result, host_log, host_note = host_compile_and_run(row)
        note = ';'.join(x for x in [sim_note, host_note] if x)
        if sim_note or host_note or not sim_result or not host_result:
            status = 'FAILED'
            if not note:
                note = 'missing_result_line'
        elif sim_result == host_result:
            status = 'MATCH'
        else:
            status = 'MISMATCH'
        results.append({
            'suite': suite,
            'function': function,
            'path': row['path'],
            'status': status,
            'sim_result': sim_result,
            'host_result': host_result,
            'sim_log': str(sim_log),
            'host_log': str(host_log),
            'note': note,
        })
        print(f'    {status}: sim=[{sim_result}] host=[{host_result}] {note}', flush=True)
        write_reports(results)
    write_reports(results)
    return 0 if all(r['status'] == 'MATCH' for r in results) else 1


if __name__ == '__main__':
    sys.exit(main())
