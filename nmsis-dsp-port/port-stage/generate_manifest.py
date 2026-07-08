#!/usr/bin/env python3
import csv
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parents[1]
DSP = ROOT / "vendor" / "NMSIS" / "DSP"
OUT = ROOT / "manifests"

MATH_RE = re.compile(r"\b(?:sqrtf?|sinf?|cosf?|logf?|expf?|powf?|atan2f?|floorf?|ceilf?)\s*\(")

def flags(path):
    text = path.read_text(errors="ignore")
    return {
        "libm": bool(MATH_RE.search(text)),
        "float16": "RISCV_FLOAT16_SUPPORTED" in text or "_f16" in path.name.lower(),
        "vector": "RISCV_MATH_VECTOR" in text or "RVV" in path.name,
        "patterns": "Pattern" in text or "Testing" in path.parts,
    }

rows = []
sets = [
    ("benchmark_c", DSP / "Benchmark", "test_*.c"),
    ("legacy_c", DSP / "Test", "*.c"),
    ("testing_cpp", DSP / "Testing" / "Source" / "Tests", "*.cpp"),
    ("testing_benchmark_cpp", DSP / "Testing" / "Source" / "Benchmarks", "*.cpp"),
    ("example_c", DSP / "Examples", "*.c"),
]
for kind, base, pattern in sets:
    for path in sorted(base.rglob(pattern)):
        info = flags(path)
        relative = path.relative_to(DSP)
        family = relative.parts[1] if len(relative.parts) > 2 else relative.parent.name
        blockers = []
        if info["libm"]: blockers.append("libm")
        if info["float16"]: blockers.append("float16")
        if info["vector"]: blockers.append("vector")
        if kind.startswith("testing_"): blockers.append("pattern_io_cpp_runtime")
        if kind == "example_c": blockers.append("example_runtime")
        rows.append({
            "kind": kind,
            "family": family,
            "path": str(relative),
            "language": "c++" if path.suffix == ".cpp" else "c",
            "migration": "source_migrated",
            "deferred_dependencies": ";".join(blockers),
        })

OUT.mkdir(exist_ok=True)
with (OUT / "dsp_tests.csv").open("w", newline="") as stream:
    fieldnames = [
        "kind",
        "family",
        "path",
        "language",
        "migration",
        "deferred_dependencies",
    ]
    writer = csv.DictWriter(stream, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(rows)

sources = sorted((DSP / "Source").rglob("*.c"))
with (OUT / "dsp_sources.txt").open("w") as stream:
    for path in sources:
        stream.write(str(path.relative_to(DSP)) + "\n")

summary = {}
for row in rows:
    summary[row["kind"]] = summary.get(row["kind"], 0) + 1
with (OUT / "SUMMARY.md").open("w") as stream:
    stream.write("# Migrated NMSIS DSP Inventory\n\n")
    stream.write(f"- Algorithm C sources: {len(sources)}\n")
    for kind, count in sorted(summary.items()):
        stream.write(f"- {kind}: {count}\n")
    stream.write(f"- Total test sources: {len(rows)}\n\n")
    stream.write("All listed sources are copied into the Zircon tree. Entries in "
                 "`deferred_dependencies` require later runtime work before linking or execution.\n")

print(f"Wrote {len(rows)} test entries and {len(sources)} algorithm entries")
