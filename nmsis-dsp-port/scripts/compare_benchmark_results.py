#!/usr/bin/env python3
import csv
import re
import shlex
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LOG_ROOT = ROOT / "build" / "benchmark-result-compare"
SIM_LOG_DIR = LOG_ROOT / "sim"
HOST_LOG_DIR = LOG_ROOT / "host"
HOST_BIN_DIR = LOG_ROOT / "host-bin"
RESULT_CSV = ROOT / "manifests" / "benchmark_result_compare.csv"
RESULT_MD = ROOT / "manifests" / "BENCHMARK_RESULT_COMPARE.md"

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
"""

NUMERIC_TYPES = (
    "float32_t",
    "float64_t",
    "q7_t",
    "q15_t",
    "q31_t",
    "q63_t",
    "uint8_t",
    "uint16_t",
    "uint32_t",
    "uint64_t",
    "int8_t",
    "int16_t",
    "int32_t",
    "int64_t",
    "uint_fast16_t",
    "int",
    "unsigned",
    "riscv_status",
)

OUTPUT_NAME_RE = re.compile(
    r"(?:output|result|status|err|error|index|pSinVal|pCosVal|pIalpha|pIbeta|"
    r"pId|pIq|Ia_|Ib_)",
    re.IGNORECASE,
)


def run_cmd(cmd, log_path, timeout=600):
    log_path.parent.mkdir(parents=True, exist_ok=True)
    with log_path.open("w") as log:
        log.write("$ " + " ".join(shlex.quote(str(c)) for c in cmd) + "\n")
        log.flush()
        proc = subprocess.run(
            cmd,
            cwd=ROOT,
            stdout=log,
            stderr=subprocess.STDOUT,
            timeout=timeout,
            text=True,
        )
    return proc.returncode


def generated_suites():
    suites_mk = ROOT / "generated" / "benchmark" / "suites.mk"
    text = suites_mk.read_text()
    match = re.search(r"BENCHMARK_SUITES\s*:=\s*(.*)", text)
    if not match:
        raise RuntimeError(f"cannot parse {suites_mk}")
    return match.group(1).split()


def parse_sources(suite):
    mk = ROOT / "generated" / "benchmark" / suite / "sources.mk"
    sources = []
    active = False
    for line in mk.read_text().splitlines():
        stripped = line.strip()
        if stripped.startswith("TEST_SRCS"):
            active = True
            continue
        if active:
            if not stripped:
                continue
            src = stripped.rstrip("\\").strip()
            if src:
                sources.append(src)
    return sources


def find_function_body(text):
    match = re.search(r"void\s+([A-Za-z_]\w*)\s*\([^)]*\)\s*\{", text)
    if not match:
        return None
    start = match.end() - 1
    depth = 0
    for idx in range(start, len(text)):
        ch = text[idx]
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return match.group(1), start, idx + 1
    return None


def split_declarators(decl):
    parts = []
    cur = []
    depth = 0
    for ch in decl:
        if ch == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
            continue
        cur.append(ch)
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
    if cur:
        parts.append("".join(cur).strip())
    return parts


def declarator_name(part):
    part = part.split("=")[0].strip().replace("*", " ")
    match = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^;]+\])?\s*$", part)
    return match.group(1) if match else None


def collect_items(text):
    body_info = find_function_body(text)
    if not body_info:
        return None, [], []
    function, body_start, body_end = body_info
    body = text[body_start:body_end]
    bench = re.search(r"BENCH_END\s*\([^;]+;\s*", body)
    if not bench:
        return function, [], []
    before = body[: bench.start()]
    type_pat = "|".join(re.escape(t) for t in NUMERIC_TYPES)
    arrays = []
    scalars = []
    array_names = set()
    for match in re.finditer(r"\b(?:" + type_pat + r")\s+([^;]+);", before):
        for part in split_declarators(match.group(1)):
            name = declarator_name(part)
            if not name or name == "i" or not OUTPUT_NAME_RE.search(name):
                continue
            if "[" in part:
                if name not in array_names:
                    array_names.add(name)
                    arrays.append({"name": name, "decl": part})
            elif name not in scalars:
                scalars.append(name)
    return function, arrays, scalars


def strip_injected_result(text):
    pattern = (
        r"\n\s*uint32_t __zr_hash = 2166136261u;\n"
        r"(?:\s*__zr_hash = zircon_result_hash_combine\([^\n]*\);\n)*"
        r"\s*printf\(\"@@RESULT@@[^\n]*\);\n"
    )
    return re.sub(pattern, "\n", text)


def hash_length_expr(function, item):
    name = item["name"]
    if "cmplx_mag" in function and re.search(r"\[\s*2\s*\*", item["decl"]):
        return f"(uint32_t)(sizeof({name}) / 2u)"
    return f"(uint32_t)sizeof({name})"


def instrument_file(path):
    text = path.read_text(errors="ignore")
    if "@@RESULT@@" in text and "__zr_hash" not in text:
        return False
    text = strip_injected_result(text)
    body_info = find_function_body(text)
    if not body_info:
        return False
    function, body_start, body_end = body_info
    body = text[body_start:body_end]
    bench = re.search(r"BENCH_END\s*\([^;]+;\s*", body)
    if not bench:
        return False
    _, arrays, scalars = collect_items(text)
    lines = ["", "    uint32_t __zr_hash = 2166136261u;"]
    for item in arrays:
        name = item["name"]
        lines.append(
            f"    __zr_hash = zircon_result_hash_combine(__zr_hash, {name}, {hash_length_expr(function, item)});"
        )
    for name in scalars:
        lines.append(
            f"    __zr_hash = zircon_result_hash_combine(__zr_hash, &{name}, (uint32_t)sizeof({name}));"
        )
    if len(lines) == 2:
        lines.append(
            "    __zr_hash = zircon_result_hash_combine(__zr_hash, &__zr_hash, (uint32_t)sizeof(__zr_hash));"
        )
    lines.append(
        f'    printf("@@RESULT@@ case={function} hash=0x%08x\\n", (unsigned int)__zr_hash);'
    )
    insertion = "\n".join(lines) + "\n"
    body = body[: bench.end()] + insertion + body[bench.end() :]
    text = text[:body_start] + body + text[body_end:]
    if "static uint32_t zircon_result_hash_combine" not in text:
        text = text.replace("BENCH_DECLARE_VAR();\n", "BENCH_DECLARE_VAR();\n" + HELPER + "\n", 1)
    path.write_text(text)
    return True


def instrument_benchmark_sources(suites):
    changed = 0
    seen = set()
    for suite in suites:
        for src in parse_sources(suite):
            if not src.startswith("vendor/NMSIS/DSP/Benchmark/") or not src.endswith(".c"):
                continue
            path = ROOT / src
            if path in seen:
                continue
            seen.add(path)
            if instrument_file(path):
                changed += 1
    return changed


def result_map(log_path):
    results = {}
    if not log_path.exists():
        return results
    for line in log_path.read_text(errors="ignore").splitlines():
        if "@@RESULT@@" not in line:
            continue
        match = re.search(r"case=([^ \t]+).*?(?:hash|checksum)=0x([0-9a-fA-F]+)", line)
        if not match:
            continue
        result_line = line[line.find("@@RESULT@@"):].strip()
        results[match.group(1)] = result_line
    return results


def compile_host(suite):
    sources = parse_sources(suite)
    c_sources = [s for s in sources if s.endswith(".c") and s != "port/src/compat_runtime.c"]
    bin_path = HOST_BIN_DIR / suite
    compile_log = HOST_LOG_DIR / f"{suite}.compile.log"
    cmd = [
        "gcc",
        "-std=gnu99",
        "-O2",
        "-Wall",
        "-Wextra",
        "-Wno-unused-function",
        "-Wno-unused-variable",
        "-Wno-unused-parameter",
        "-iquote",
        str(ROOT / "port/include"),
    ]
    for inc in [
        "vendor/NMSIS/DSP/Include",
        "vendor/NMSIS/DSP/PrivateInclude",
        "vendor/NMSIS/DSP/Benchmark",
        f"vendor/NMSIS/DSP/Benchmark/{suite}",
    ]:
        cmd += ["-I", str(ROOT / inc)]
    cmd += ["-o", str(bin_path)]
    cmd += [str(ROOT / src) for src in c_sources]
    cmd += ["-lm"]
    return run_cmd(cmd, compile_log, timeout=300), bin_path, compile_log


def run_suite(suite):
    sim_log = SIM_LOG_DIR / f"{suite}.log"
    sim_cmd = [
        "make",
        "-C",
        str(ROOT),
        "TEST_SYSTEM=benchmark",
        f"SUITE={suite}",
        "USE_SIMULATOR_ONLY_MODE=1",
        "run",
    ]
    sim_rc = run_cmd(sim_cmd, sim_log, timeout=900)
    host_compile_rc, host_bin, host_compile_log = compile_host(suite)
    host_log = HOST_LOG_DIR / f"{suite}.run.log"
    host_rc = None
    if host_compile_rc == 0:
        host_rc = run_cmd([str(host_bin)], host_log, timeout=300)
    return {
        "suite": suite,
        "sim_rc": sim_rc,
        "host_compile_rc": host_compile_rc,
        "host_rc": host_rc,
        "sim_log": sim_log,
        "host_compile_log": host_compile_log,
        "host_log": host_log,
        "sim_results": result_map(sim_log),
        "host_results": result_map(host_log),
    }


def compare_suite(run):
    rows = []
    suite = run["suite"]
    sim_results = run["sim_results"]
    host_results = run["host_results"]
    cases = sorted(set(sim_results) | set(host_results))
    if run["sim_rc"] != 0:
        rows.append(
            {
                "suite": suite,
                "case": "<suite>",
                "status": "SIM_FAILED",
                "sim_result": "",
                "host_result": "",
                "sim_log": str(run["sim_log"]),
                "host_log": str(run["host_log"]),
                "note": f"sim_rc={run['sim_rc']}",
            }
        )
    if run["host_compile_rc"] != 0:
        rows.append(
            {
                "suite": suite,
                "case": "<suite>",
                "status": "HOST_COMPILE_FAILED",
                "sim_result": "",
                "host_result": "",
                "sim_log": str(run["sim_log"]),
                "host_log": str(run["host_compile_log"]),
                "note": f"host_compile_rc={run['host_compile_rc']}",
            }
        )
        return rows
    if run["host_rc"] not in (0, None):
        rows.append(
            {
                "suite": suite,
                "case": "<suite>",
                "status": "HOST_RUN_FAILED",
                "sim_result": "",
                "host_result": "",
                "sim_log": str(run["sim_log"]),
                "host_log": str(run["host_log"]),
                "note": f"host_rc={run['host_rc']}",
            }
        )
    for case in cases:
        sim = sim_results.get(case, "")
        host = host_results.get(case, "")
        if not sim or not host:
            status = "MISSING_RESULT"
        elif sim == host:
            status = "MATCH"
        else:
            status = "MISMATCH"
        rows.append(
            {
                "suite": suite,
                "case": case,
                "status": status,
                "sim_result": sim,
                "host_result": host,
                "sim_log": str(run["sim_log"]),
                "host_log": str(run["host_log"]),
                "note": "",
            }
        )
    return rows


def write_reports(rows):
    RESULT_CSV.parent.mkdir(parents=True, exist_ok=True)
    fields = ["suite", "case", "status", "sim_result", "host_result", "sim_log", "host_log", "note"]
    with RESULT_CSV.open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fields)
        writer.writeheader()
        for row in rows:
            writer.writerow({k: row.get(k, "") for k in fields})
    total = len([r for r in rows if r["case"] != "<suite>"])
    match = sum(1 for r in rows if r["status"] == "MATCH")
    mismatch = sum(1 for r in rows if r["status"] == "MISMATCH")
    missing = sum(1 for r in rows if r["status"] == "MISSING_RESULT")
    failures = [r for r in rows if r["status"] not in ("MATCH",)]
    lines = [
        "# Benchmark Result Compare",
        "",
        f"- Result-bearing cases: {total}",
        f"- Match: {match}",
        f"- Mismatch: {mismatch}",
        f"- Missing result line: {missing}",
        f"- CSV: `manifests/{RESULT_CSV.name}`",
        f"- Logs: `{LOG_ROOT.relative_to(ROOT)}`",
        "",
        "## Non-Matching Or Failed Cases",
        "",
    ]
    if not failures:
        lines.append("No mismatches or run failures were observed.")
    else:
        lines.append("| Suite | Case | Status | Sim Result | Host Result | Note |")
        lines.append("| --- | --- | --- | --- | --- | --- |")
        for row in failures:
            lines.append(
                "| {suite} | `{case}` | {status} | `{sim}` | `{host}` | {note} |".format(
                    suite=row["suite"],
                    case=row["case"],
                    status=row["status"],
                    sim=row.get("sim_result", "").replace("|", "\\|"),
                    host=row.get("host_result", "").replace("|", "\\|"),
                    note=row.get("note", ""),
                )
            )
    RESULT_MD.write_text("\n".join(lines) + "\n")


def main():
    suites = generated_suites()
    clean_log = ROOT / "manifests" / "benchmark_result_compare_clean.log"
    run_cmd(["make", "-s", "-C", str(ROOT.parent.parent / "ZirconSim"), "clean"], clean_log)
    run_cmd(["make", "-C", str(ROOT), "clean"], clean_log)
    LOG_ROOT.mkdir(parents=True, exist_ok=True)
    SIM_LOG_DIR.mkdir(parents=True, exist_ok=True)
    HOST_LOG_DIR.mkdir(parents=True, exist_ok=True)
    HOST_BIN_DIR.mkdir(parents=True, exist_ok=True)
    changed = instrument_benchmark_sources(suites)
    print(f"instrumented {changed} benchmark source files")
    rows = []
    for idx, suite in enumerate(suites, 1):
        print(f"[{idx}/{len(suites)}] {suite}", flush=True)
        suite_rows = compare_suite(run_suite(suite))
        rows.extend(suite_rows)
        write_reports(rows)
        bad = [r for r in suite_rows if r["status"] not in ("MATCH",)]
        print(f"    rows={len(suite_rows)} bad={len(bad)}", flush=True)
    write_reports(rows)
    return 0 if all(r["status"] == "MATCH" for r in rows) else 1


if __name__ == "__main__":
    sys.exit(main())
