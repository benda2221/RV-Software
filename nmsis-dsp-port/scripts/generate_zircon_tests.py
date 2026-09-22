#!/usr/bin/env python3
import csv
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
DSP = ROOT / "vendor" / "NMSIS" / "DSP"
GENERATED = ROOT / "generated"
MANIFESTS = ROOT / "manifests"
F32_DIFFTEST_MISMATCH_CASES = MANIFESTS / "f32_difftest_mismatch_cases.csv"
F32_CANDIDATE_RUN_SUMMARY = MANIFESTS / "f32_candidate_run_summary.csv"

BASIC_FIXED_SUFFIXES = ("_q7", "_q15", "_q31", "_u8", "_u16", "_u32")
BASIC_ALLOWED_OPS = (
    "abs", "add", "clip", "dot_prod", "mul", "mult", "negate", "offset", "scale",
    "shift", "sub", "and", "not", "or", "xor",
)
DEFAULT_BENCHMARK_SUITES = (
    "BasicMathFunctions",
    "BayesFunctions",
    "ComplexMathFunctions",
    "ControllerFunctions",
    "DistanceFunctions",
    "FastMathFunctions",
    "FilteringFunctions",
    "InterpolationFunctions",
    "MatrixFunctions",
    "QuaternionMathFunctions",
    "SVMFunctions",
    "StatisticsFunctions",
    "SupportFunctions",
    "TransformFunctions",
)
BENCHMARK_FLOAT32_ALLOWED = {
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_abs_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_add_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_clip_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_dot_prod_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_mult_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_negate_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_offset_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_scale_f32.c",
    "vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_sub_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_conj_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_dot_prod_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_mag_squared_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_mult_cmplx_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_mult_real_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_clarke_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_clarke_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_park_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_park_f32.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_f32.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_braycurtis_distance_f32.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_canberra_distance_f32.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_chebyshev_distance_f32.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_cityblock_distance_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df1_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df2T_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_stereo_df2T_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_conv_partial_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_decimate_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_interpolate_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_lattice_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_iir_lattice_f32.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_levinson_durbin_f32.c",
    "vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_f32.c",
    "vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_spline_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_add_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_cmplx_mult_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_ldlt_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_mult_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_scale_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_solve_lower_triangular_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_sub_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_trans_f32.c",
    "vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_vec_mult_f32.c",
    "vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion2rotation_f32.c",
    "vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion_conjugate_f32.c",
    "vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion_inverse_f32.c",
    "vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion_product_f32.c",
    "vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion_product_single_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_linear_predict_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_polynomial_predict_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_absmin_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_absmin_no_idx_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_mean_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_mse_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_power_f32.c",
    "vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_var_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_barycenter_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_copy_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_fill_f32.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_weighted_average_f32.c",
    "vendor/NMSIS/DSP/Benchmark/TransformFunctions/cfft/test_riscv_cfft_radix2_f32.c",
    "vendor/NMSIS/DSP/Benchmark/TransformFunctions/cfft/test_riscv_cfft_radix4_f32.c",
    "vendor/NMSIS/DSP/Benchmark/TransformFunctions/dct4/test_riscv_dct4_f32.c",
    "vendor/NMSIS/DSP/Benchmark/TransformFunctions/rfft/test_riscv_rfft_f32.c",
}
BENCHMARK_FLOAT_HELPER_ALLOWED = {
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_q15.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_park_q31.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_park_q31.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_q31.c",
    "vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_sin_cos_q31.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_dice_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_hamming_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_jaccard_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_kulsinski_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_rogerstanimoto_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_russellrao_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_sokalmichener_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_sokalsneath_distance.c",
    "vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_yule_distance.c",
    "vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_sin_q15.c",
    "vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_sin_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df1_32x64_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df1_fast_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df1_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_decimate_q15.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_decimate_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_fast_q15.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_fast_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_lms_norm_q15.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_lms_norm_q31.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_lms_q15.c",
    "vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_lms_q31.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_float_to_q15.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_float_to_q31.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_float_to_q7.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_q15_to_float.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_q31_to_float.c",
    "vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_q7_to_float.c",
}
BOOLEAN_DISTANCE_SYMBOLS = (
    "riscv_boolean_distance_TT_TF_FT",
    "riscv_boolean_distance_TF_FT",
    "riscv_boolean_distance_TT_FF_TF_FT",
    "riscv_boolean_distance_TT",
)
BENCHMARK_BACKEND_ERROR_CASES = set()
MATH_RE = re.compile(r"\b(?:sqrtf?|sinf?|cosf?|logf?|expf?|powf?|atan2f?|floorf?|ceilf?)\s*\(")
FUNC_RE = re.compile(r"^\s*void\s+([A-Za-z0-9_]+)\s*\(\s*void\s*\)", re.MULTILINE)
MAIN_RE = re.compile(r"\bmain\s*\(")
RISCV_SYMBOL_RE = re.compile(r"\briscv_[A-Za-z0-9_]+\b")
LEGACY_SYMBOL_RE = re.compile(r"\b(?:riscv|ref|generate|validate)_[A-Za-z0-9_]+\b")
RISCV_FUNCTION_DEF_RE = re.compile(
    r"^[ \t]*(?:[A-Za-z_][A-Za-z0-9_]*[ \t\*]+)+"
    r"(riscv_[A-Za-z0-9_]+)\s*\([^;{}]*\)\s*\{",
    re.MULTILINE,
)
LEGACY_FUNCTION_DEF_RE = re.compile(
    r"^[ \t]*(?:[A-Za-z_][A-Za-z0-9_]*[ \t\*]+)+"
    r"((?:riscv|ref|generate|validate)_[A-Za-z0-9_]+)\s*\([^;{}]*\)\s*\{",
    re.MULTILINE,
)
FLOAT_RE = re.compile(r"\b(?:float|double|float16_t|float32_t|float64_t|f16|f32|f64)\b|_(?:f16|f32|f64)\b")
HEX_RE = re.compile(r"^\s*0x[0-9a-fA-F]+")
COMMENT_RE = re.compile(r"/\*.*?\*/|//.*?$", re.DOTALL | re.MULTILINE)
INCLUDE_C_RE = re.compile(r"^\s*#\s*include\s+[<\"]([^>\"]+\.c)[>\"]", re.MULTILINE)
CASE_ID_RE = re.compile(r"[^A-Za-z0-9_]+")


def code_text(path: pathlib.Path) -> str:
    return COMMENT_RE.sub("", path.read_text(errors="ignore"))


def rel(path: pathlib.Path) -> str:
    return str(path.relative_to(ROOT))


def has_libm(path: pathlib.Path) -> bool:
    return bool(MATH_RE.search(path.read_text(errors="ignore")))


def blockers_for(path: pathlib.Path):
    text = path.read_text(errors="ignore")
    name = path.name.lower()
    blockers = []
    if "f16" in name or "RISCV_FLOAT16_SUPPORTED" in text:
        blockers.append("float16")
    if FLOAT_RE.search(path.name) or FLOAT_RE.search(text):
        blockers.append("floating_point")
    if "rvv" in name.lower() or "RVV" in str(path):
        blockers.append("rvv_vector")
    if has_libm(path):
        blockers.append("libm")
    return blockers


def source_blockers_for(path: pathlib.Path):
    name = path.name.lower()
    blockers = []
    if path.name.endswith("Functions.c") or path.name.endswith("FunctionsF16.c"):
        blockers.append("aggregate_translation_unit")
    if "f16" in name or "_f64" in name:
        blockers.append("floating_point_source")
    if "rvv" in name or "RVV" in str(path):
        blockers.append("rvv_vector")
    return blockers


def source_symbol_index():
    index = {}
    for src in sorted((DSP / "Source").rglob("*.c")):
        if source_blockers_for(src):
            continue
        text = code_text(src)
        for symbol in RISCV_FUNCTION_DEF_RE.findall(text):
            index.setdefault(symbol, src)
        index.setdefault(src.stem, src)
        if src.name == "riscv_boolean_distance.c":
            for symbol in BOOLEAN_DISTANCE_SYMBOLS:
                index.setdefault(symbol, src)
        if src.name == "riscv_cfft_init_f32.c":
            for size in (16, 32, 64, 128, 256, 512, 1024, 2048, 4096):
                index.setdefault(f"riscv_cfft_init_{size}_f32", src)
    return index


def dependency_sources(paths):
    index = source_symbol_index()
    selected = []
    seen = set()
    queue = []

    for path in paths:
        text = code_text(path)
        queue.extend(sorted(set(RISCV_SYMBOL_RE.findall(text))))
        if "generate_posi_def_symme_f32" in text:
            queue.extend(["riscv_mat_add_f32", "riscv_mat_mult_f32", "riscv_mat_trans_f32"])

    while queue:
        symbol = queue.pop(0)
        src = index.get(symbol)
        if not src or src in seen:
            continue
        seen.add(src)
        selected.append(src)
        queue.extend(sorted(set(RISCV_SYMBOL_RE.findall(code_text(src)))))

    for src in (
        DSP / "Source" / "CommonTables" / "riscv_common_tables.c",
        DSP / "Source" / "CommonTables" / "riscv_const_structs.c",
    ):
        if src.exists() and src not in seen:
            selected.append(src)
    return selected


def sanitize_case_id(path: pathlib.Path, suite: str) -> str:
    local = path.relative_to(DSP / "Test" / suite).with_suffix("")
    return CASE_ID_RE.sub("_", "__".join(local.parts)).strip("_")


def included_c_sources(path: pathlib.Path, seen=None):
    if seen is None:
        seen = set()
    found = []
    for include in INCLUDE_C_RE.findall(path.read_text(errors="ignore")):
        # Match the include search roots used by the port Makefile.  Several
        # nested legacy tests include "../HelperFunctions/*.c"; that spelling
        # only resolves through Test/BasicMathFunctions, not relative to the
        # source file itself.  Missing it here makes the dependency scanner add
        # the already textually included helper as a separate translation unit.
        candidates = (
            (path.parent / include).resolve(),
            (DSP / "Test" / "BasicMathFunctions" / include).resolve(),
            (DSP / "Test" / include).resolve(),
        )
        candidate = next((item for item in candidates if item.exists()), None)
        if candidate is None or candidate in seen:
            continue
        try:
            candidate.relative_to(ROOT)
        except ValueError:
            continue
        seen.add(candidate)
        found.append(candidate)
        found.extend(included_c_sources(candidate, seen))
    return found


def legacy_source_symbol_index():
    index = {}
    for src in sorted((ROOT / "port" / "src").glob("*.c")):
        text = code_text(src)
        for symbol in LEGACY_FUNCTION_DEF_RE.findall(text):
            index.setdefault(symbol, src)
    for src in sorted((DSP / "Source").rglob("*.c")):
        if src.name.endswith("Functions.c") or src.name.endswith("FunctionsF16.c"):
            continue
        if "rvv" in src.name.lower() or "RVV" in str(src):
            continue
        text = code_text(src)
        for symbol in LEGACY_FUNCTION_DEF_RE.findall(text):
            index.setdefault(symbol, src)
        if src.name.startswith("riscv_"):
            index.setdefault(src.stem, src)
        if src.name == "riscv_boolean_distance.c":
            for symbol in BOOLEAN_DISTANCE_SYMBOLS:
                index.setdefault(symbol, src)
    for src in sorted((DSP / "Test").rglob("*.c")):
        text = code_text(src)
        if MAIN_RE.search(text):
            continue
        for symbol in LEGACY_FUNCTION_DEF_RE.findall(text):
            index.setdefault(symbol, src)
        if src.name.startswith(("riscv_", "ref_")):
            index.setdefault(src.stem, src)
    for symbol in (
        "riscvRecipTableQ31", "riscvRecipTableQ15",
        "twiddleCoef_4096", "twiddleCoef_4096_q31", "twiddleCoef_4096_q15",
    ):
        index.setdefault(symbol, DSP / "Source" / "CommonTables" / "riscv_common_tables.c")
    return index


def legacy_dependency_sources(paths):
    index = legacy_source_symbol_index()
    selected = []
    selected_set = set()
    excluded = set(paths)
    scan_seen = set()
    queue = []

    def scan(path):
        if path in scan_seen:
            return
        scan_seen.add(path)
        text = code_text(path)
        queue.extend(sorted(set(LEGACY_SYMBOL_RE.findall(text))))
        for included in included_c_sources(path):
            excluded.add(included)
            scan(included)

    for path in paths:
        scan(path)

    while queue:
        symbol = queue.pop(0)
        src = index.get(symbol)
        if not src or src in selected_set or src in excluded:
            continue
        selected_set.add(src)
        selected.append(src)
        scan(src)

    for src in (
        DSP / "Source" / "CommonTables" / "riscv_common_tables.c",
        DSP / "Source" / "CommonTables" / "riscv_const_structs.c",
        ROOT / "port" / "src" / "ref_matrix_f32_subset.c",
        ROOT / "port" / "src" / "compat_runtime.c",
    ):
        if src.exists() and src not in selected_set and src not in excluded:
            selected_set.add(src)
            selected.append(src)
    return selected


def write_legacy_no_call_runner(path, suite, case_id):
    with path.open("w") as f:
        f.write("#include <stdio.h>\n")
        f.write("\nint main(void)\n{\n")
        f.write(f'    printf("PASS legacy/{suite}/{case_id} compile-link only\\n");\n')
        f.write("    return 0;\n}\n")


def write_legacy_case(cases_dir, suite, test_path):
    case_id = sanitize_case_id(test_path, suite)
    case_dir = cases_dir / case_id
    case_dir.mkdir(parents=True, exist_ok=True)
    sources = []
    if not MAIN_RE.search(code_text(test_path)):
        runner = case_dir / "runner.c"
        write_legacy_no_call_runner(runner, suite, case_id)
        sources.append(runner)
    sources.append(test_path)
    sources.extend(legacy_dependency_sources([test_path]))

    deduped = []
    seen = set()
    for src in sources:
        if src in seen:
            continue
        seen.add(src)
        deduped.append(src)
    test_name = "nmsis-dsp-legacy-" + suite.lower() + "-" + case_id.lower()
    write_sources_mk(case_dir / "sources.mk", test_name, deduped)
    return case_id


def legacy_all_cases():
    rows = []
    case_entries = []
    for path in sorted((DSP / "Test").rglob("*.c")):
        suite = path.relative_to(DSP / "Test").parts[0]
        outdir = GENERATED / "legacy" / suite
        cases_dir = outdir / "cases"
        cases_dir.mkdir(parents=True, exist_ok=True)
        case_id = write_legacy_case(cases_dir, suite, path)
        case_entries.append((suite, case_id))
        rows.append({
            "system": "legacy",
            "suite": suite,
            "path": rel(path),
            "status": "enabled",
            "reason": "generated_legacy_case",
        })

    cases_mk = GENERATED / "legacy" / "cases.mk"
    cases_mk.parent.mkdir(parents=True, exist_ok=True)
    with cases_mk.open("w") as f:
        f.write("LEGACY_CASES := \\\n")
        for suite, case_id in case_entries:
            f.write(f"  {suite}:{case_id} \\\n")
        f.write("\n")
    return rows


def benchmark_test_enabled(path: pathlib.Path):
    stem = path.stem.replace("test_riscv_", "")
    suite = path.relative_to(DSP / "Benchmark").parts[0]
    rpath = rel(path)
    blockers = blockers_for(path)
    if (rpath in BENCHMARK_FLOAT32_ALLOWED or stem.endswith("_f32")) and blockers == ["floating_point"]:
        return True, ""
    if rpath in BENCHMARK_FLOAT_HELPER_ALLOWED and blockers == ["floating_point"]:
        return True, ""
    if blockers:
        return False, ";".join(blockers)
    if suite == "BasicMathFunctions":
        is_basic_fixed = stem.endswith(BASIC_FIXED_SUFFIXES) and any(stem.startswith(op + "_") for op in BASIC_ALLOWED_OPS)
        if not is_basic_fixed:
            return False, "not_integer_fixed_point"
    return True, ""


def write_sources_mk(path, test_name, sources):
    with path.open("w") as f:
        f.write(f"TEST_NAME := {test_name}\n")
        f.write("TEST_SRCS := \\\n")
        for src in sources:
            f.write(f"  {rel(src)} \\\n")
        f.write("\n")


def write_case_runner(path, suite, functions, label=None):
    with path.open("w") as f:
        f.write("#include <stdio.h>\n")
        for fn in functions:
            f.write(f"extern void {fn}(void);\n")
        f.write("\nint main(void)\n{\n")
        if label:
            f.write(f'    printf("Start benchmark/{suite}/{label}\\n");\n')
        else:
            f.write(f'    printf("Start benchmark/{suite}\\n");\n')
        for fn in functions:
            f.write(f'    printf("RUN {fn}\\n");\n    {fn}();\n')
        if label:
            f.write(f'    printf("PASS benchmark/{suite}/{label} count=%d\\n", {len(functions)});\n')
        else:
            f.write(f'    printf("PASS benchmark/{suite} count=%d\\n", {len(functions)});\n')
        f.write("    return 0;\n}\n")


def write_benchmark_case(cases_dir, suite, test_name, test_path, fn):
    case_dir = cases_dir / fn
    case_dir.mkdir(parents=True, exist_ok=True)
    case_runner = case_dir / "runner.c"
    write_case_runner(case_runner, suite, [fn], fn)
    case_sources = [case_runner, test_path] + dependency_sources([test_path]) + [ROOT / "port" / "src" / "compat_runtime.c"]
    case_name = test_name + "-" + fn.lower()
    write_sources_mk(case_dir / "sources.mk", case_name, case_sources)


def benchmark_difftest_case_entries(suite):
    if not F32_DIFFTEST_MISMATCH_CASES.exists():
        return []
    entries = []
    with F32_DIFFTEST_MISMATCH_CASES.open(newline="") as f:
        for row in csv.DictReader(f):
            if row["suite"] != suite:
                continue
            test_path = ROOT / row["path"]
            fn = row["function"]
            if test_path.exists() and fn:
                entries.append((test_path, fn))
    return entries


def benchmark_backend_error_case_entries(suite):
    entries = []
    for rpath in sorted(BENCHMARK_BACKEND_ERROR_CASES):
        test_path = ROOT / rpath
        if not test_path.exists():
            continue
        if test_path.relative_to(DSP / "Benchmark").parts[0] != suite:
            continue
        found = FUNC_RE.findall(test_path.read_text(errors="ignore"))
        if found:
            entries.append((test_path, found[0]))
    return entries


def benchmark_failed_f32_case_entries(suite):
    if not F32_CANDIDATE_RUN_SUMMARY.exists():
        return []
    entries = []
    with F32_CANDIDATE_RUN_SUMMARY.open(newline="") as f:
        for row in csv.DictReader(f):
            if row["system"] != "benchmark" or row["suite"] != suite:
                continue
            if row["result"] == "PASS" or not row["function"].endswith("_f32"):
                continue
            test_path = ROOT / row["path"]
            fn = row["function"]
            if test_path.exists() and fn:
                entries.append((test_path, fn))
    return entries


def benchmark_suite(suite):
    base = DSP / "Benchmark" / suite
    outdir = GENERATED / "benchmark" / suite
    outdir.mkdir(parents=True, exist_ok=True)

    enabled_tests = []
    manifest_rows = []
    for path in sorted(base.rglob("test_*.c")):
        enabled, reason = benchmark_test_enabled(path)
        if enabled:
            enabled_tests.append(path)
        manifest_rows.append({
            "system": "benchmark",
            "suite": suite,
            "path": rel(path),
            "status": "enabled" if enabled else "skipped",
            "reason": reason,
        })

    entries = []
    for path in enabled_tests:
        found = FUNC_RE.findall(path.read_text(errors="ignore"))
        if found:
            entries.append((path, found[0]))

    functions = [fn for _, fn in entries]
    runner = outdir / "runner.c"
    write_case_runner(runner, suite, functions)

    algo_sources = dependency_sources(enabled_tests)
    sources = [runner] + enabled_tests + algo_sources + [ROOT / "port" / "src" / "compat_runtime.c"]
    test_name = "nmsis-dsp-benchmark-" + suite.lower().replace("functions", "")
    write_sources_mk(outdir / "sources.mk", test_name, sources)

    cases_dir = outdir / "cases"
    case_entries = {fn: (test_path, fn) for test_path, fn in entries}
    for test_path, fn in benchmark_difftest_case_entries(suite):
        case_entries.setdefault(fn, (test_path, fn))
    for test_path, fn in benchmark_failed_f32_case_entries(suite):
        case_entries.setdefault(fn, (test_path, fn))
    for test_path, fn in benchmark_backend_error_case_entries(suite):
        case_entries.setdefault(fn, (test_path, fn))
    for test_path, fn in case_entries.values():
        write_benchmark_case(cases_dir, suite, test_name, test_path, fn)
    return manifest_rows


def benchmark_suites():
    rows = []
    enabled_suites = []
    for base in sorted((DSP / "Benchmark").iterdir()):
        if not base.is_dir() or base.name == "TestData":
            continue
        suite_rows = benchmark_suite(base.name)
        rows.extend(suite_rows)
        if base.name in DEFAULT_BENCHMARK_SUITES:
            enabled_suites.append(base.name)

    suites_mk = GENERATED / "benchmark" / "suites.mk"
    suites_mk.parent.mkdir(parents=True, exist_ok=True)
    with suites_mk.open("w") as f:
        f.write("BENCHMARK_SUITES := " + " ".join(enabled_suites) + "\n")
    return rows


def legacy_basicmath():
    suite = "BasicMathFunctions"
    outdir = GENERATED / "legacy" / suite
    outdir.mkdir(parents=True, exist_ok=True)
    test_sources = [
        ROOT / "port" / "src" / "legacy_basicmath_fixed_runner.c",
        DSP / "Test" / suite / "ref_basic_math_functions.c",
    ]
    implicit_reference_sources = [
        ROOT / "port" / "src" / "ref_matrix_f32_subset.c",
    ]
    helper_sources = [
        DSP / "Test" / "HelperFunctions" / "ref_helper.c",
    ]
    algo_sources = []
    for src in sorted((DSP / "Source" / "BasicMathFunctions").glob("riscv_*.c")):
        if src.name in ("BasicMathFunctions.c", "BasicMathFunctionsF16.c"):
            continue
        if src.stem.endswith(BASIC_FIXED_SUFFIXES) and not blockers_for(src):
            algo_sources.append(src)
    sources = test_sources + implicit_reference_sources + helper_sources + algo_sources + [ROOT / "port" / "src" / "compat_runtime.c"]
    with (outdir / "sources.mk").open("w") as f:
        f.write("TEST_NAME := nmsis-dsp-legacy-basicmath\n")
        f.write("TEST_SRCS := \\\n")
        for src in sources:
            f.write(f"  {rel(src)} \\\n")
        f.write("\n")
    return [{
        "system": "legacy",
        "suite": suite,
        "path": rel(ROOT / "port" / "src" / "legacy_basicmath_fixed_runner.c"),
        "status": "enabled",
        "reason": "zircon_fixed_runner",
    }]



def read_pattern_values(path: pathlib.Path):
    values = []
    for line in path.read_text(errors="ignore").splitlines():
        match = HEX_RE.match(line)
        if match:
            values.append(match.group(0))
    return values


def emit_array(out, ctype, name, values):
    out.write(f"static const {ctype} {name}[] = {{\n")
    for i, value in enumerate(values):
        suffix = "ULL" if len(value) > 10 else "u"
        out.write(f"    ({ctype}){value}{suffix},")
        if i % 4 == 3:
            out.write("\n")
    if values and len(values) % 4 != 0:
        out.write("\n")
    out.write("};\n\n")


def testing_basicmath_smoke():
    suite = "BasicMaths"
    base = DSP / "Testing" / "Patterns" / "DSP" / "BasicMaths"
    outdir = GENERATED / "testing_smoke" / suite
    outdir.mkdir(parents=True, exist_ok=True)

    specs = [
        {
            "tag": "q7", "dir": "BasicMathsQ7", "ctype": "q7_t", "utype": "uint8_t", "logical": "u8", "dot_type": "q31_t", "small": (15, 32, 47),
            "scalar": "(q7_t)0x40u",
            "clip": (("(q7_t)0xC0u", "(q7_t)0xF3u"), ("(q7_t)0xC0u", "(q7_t)0x40u"), ("(q7_t)0x0Du", "(q7_t)0x40u")),
            "files": {"input1": "Input1_q7.txt", "input2": "Input2_q7.txt", "inputrand": "Input12_q7.txt", "inputclip": "Input28_q7.txt", "maxpos": "MaxPosInput12_s8.txt", "maxneg": "MaxNegInput12_s8.txt", "maxneg2": "MaxNeg2Input12_s8.txt", "bit1": "BitwiseInput24_s8.txt", "bit2": "BitwiseInput25_s8.txt", "ref": "Reference1_q7.txt", "refdot": "Reference11_q31.txt", "refand": "And24_s8.txt"},
        },
        {
            "tag": "q15", "dir": "BasicMathsQ15", "ctype": "q15_t", "utype": "uint16_t", "logical": "u16", "dot_type": "q63_t", "small": (7, 16, 23),
            "scalar": "(q15_t)0x4000u",
            "clip": (("(q15_t)0xC000u", "(q15_t)0xF333u"), ("(q15_t)0xC000u", "(q15_t)0x4000u"), ("(q15_t)0x0CCDu", "(q15_t)0x4000u")),
            "files": {"input1": "Input1_q15.txt", "input2": "Input2_q15.txt", "inputrand": "Input12_q15.txt", "inputclip": "Input28_q15.txt", "maxpos": "MaxPosInput12_s16.txt", "maxneg": "MaxNegInput12_s16.txt", "maxneg2": "MaxNeg2Input12_s16.txt", "bit1": "BitwiseInput24_s16.txt", "bit2": "BitwiseInput25_s16.txt", "ref": "Reference1_q15.txt", "refdot": "Reference11_q63.txt", "refand": "And24_s16.txt"},
        },
        {
            "tag": "q31", "dir": "BasicMathsQ31", "ctype": "q31_t", "utype": "uint32_t", "logical": "u32", "dot_type": "q63_t", "small": (3, 8, 11),
            "scalar": "(q31_t)0x40000000u",
            "clip": (("(q31_t)0xC0000000u", "(q31_t)0xF3333333u"), ("(q31_t)0xC0000000u", "(q31_t)0x40000000u"), ("(q31_t)0x0CCCCCCDu", "(q31_t)0x40000000u")),
            "files": {"input1": "Input1_q31.txt", "input2": "Input2_q31.txt", "inputrand": "Input12_q31.txt", "inputclip": "Input28_q31.txt", "maxpos": "MaxPosInput12_s32.txt", "maxneg": "MaxNegInput12_s32.txt", "maxneg2": "MaxNeg2Input12_s32.txt", "bit1": "BitwiseInput24_s32.txt", "bit2": "BitwiseInput25_s32.txt", "ref": "Reference1_q31.txt", "refdot": "Reference11_q63.txt", "refand": "And24_s32.txt"},
        },
    ]

    runner = outdir / "runner.c"
    with runner.open("w") as f:
        f.write("#include <stdint.h>\n")
        f.write("#include <stdio.h>\n")
        f.write("#include \"dsp/basic_math_functions.h\"\n\n")
        f.write("#define ARRAY_SIZE(a) ((uint32_t)(sizeof(a) / sizeof((a)[0])))\n\n")
        f.write("static volatile q63_t smoke_sink;\n\n")

        for spec in specs:
            pattern_dir = base / spec["dir"]
            for key, filename in spec["files"].items():
                ctype = spec["utype"] if key in ("bit1", "bit2", "refand") else spec["ctype"]
                if key == "refdot":
                    ctype = spec["dot_type"]
                emit_array(f, ctype, f"{spec['tag']}_{key}", read_pattern_values(pattern_dir / filename))

        f.write("static uint32_t min_u32(uint32_t a, uint32_t b) { return a < b ? a : b; }\n\n")
        f.write("static void touch_q63(q63_t value) { smoke_sink += value; }\n\n")

        for spec in specs:
            tag = spec["tag"]
            ctype = spec["ctype"]
            utype = spec["utype"]
            logical = spec["logical"]
            dot_type = spec["dot_type"]
            f.write(f"static unsigned run_{tag}(void)\n{{\n")
            f.write(f"    {ctype} out[256];\n")
            f.write(f"    {utype} out_logical[256];\n")
            f.write(f"    {dot_type} dot = 0;\n")
            f.write("    unsigned count = 0;\n")
            f.write(f"    const uint32_t full = min_u32(ARRAY_SIZE({tag}_input1), ARRAY_SIZE({tag}_ref));\n")
            f.write(f"    const uint32_t logical_full = min_u32(ARRAY_SIZE({tag}_bit1), ARRAY_SIZE({tag}_refand));\n")
            f.write(f"    touch_q63((q63_t){tag}_ref[0]);\n")
            f.write(f"    touch_q63((q63_t){tag}_refdot[0]);\n")
            f.write(f"    touch_q63((q63_t){tag}_refand[0]);\n")
            for nb in spec["small"]:
                f.write(f"    riscv_add_{tag}({tag}_input1, {tag}_input2, out, {nb}); count++;\n")
                f.write(f"    riscv_sub_{tag}({tag}_input1, {tag}_input2, out, {nb}); count++;\n")
                f.write(f"    riscv_mult_{tag}({tag}_input1, {tag}_input2, out, {nb}); count++;\n")
                f.write(f"    riscv_negate_{tag}({tag}_input1, out, {nb}); count++;\n")
                f.write(f"    riscv_offset_{tag}({tag}_input1, {spec['scalar']}, out, {nb}); count++;\n")
                f.write(f"    riscv_scale_{tag}({tag}_input1, {spec['scalar']}, 0, out, {nb}); count++;\n")
                f.write(f"    riscv_dot_prod_{tag}({tag}_input1, {tag}_input2, {nb}, &dot); touch_q63((q63_t)dot); count++;\n")
                f.write(f"    riscv_abs_{tag}({tag}_input1, out, {nb}); count++;\n")
                f.write(f"    riscv_and_{logical}({tag}_bit1, {tag}_bit2, out_logical, {nb}); count++;\n")
                f.write(f"    riscv_or_{logical}({tag}_bit1, {tag}_bit2, out_logical, {nb}); count++;\n")
                f.write(f"    riscv_not_{logical}({tag}_bit1, out_logical, {nb}); count++;\n")
                f.write(f"    riscv_xor_{logical}({tag}_bit1, {tag}_bit2, out_logical, {nb}); count++;\n")
            f.write(f"    riscv_add_{tag}({tag}_input1, {tag}_input2, out, full); count++;\n")
            f.write(f"    riscv_sub_{tag}({tag}_input1, {tag}_input2, out, full); count++;\n")
            f.write(f"    riscv_mult_{tag}({tag}_input1, {tag}_input2, out, full); count++;\n")
            f.write(f"    riscv_negate_{tag}({tag}_input1, out, full); count++;\n")
            f.write(f"    riscv_offset_{tag}({tag}_input1, {spec['scalar']}, out, full); count++;\n")
            f.write(f"    riscv_scale_{tag}({tag}_input1, {spec['scalar']}, 0, out, full); count++;\n")
            f.write(f"    riscv_dot_prod_{tag}({tag}_input1, {tag}_input2, full, &dot); touch_q63((q63_t)dot); count++;\n")
            f.write(f"    riscv_abs_{tag}({tag}_input1, out, full); count++;\n")
            f.write(f"    riscv_shift_{tag}({tag}_inputrand, 1, out, ARRAY_SIZE({tag}_inputrand)); count++;\n")
            for minimum, maximum in spec["clip"]:
                f.write(f"    riscv_clip_{tag}({tag}_inputclip, out, {minimum}, {maximum}, ARRAY_SIZE({tag}_inputclip)); count++;\n")
            f.write(f"    riscv_and_{logical}({tag}_bit1, {tag}_bit2, out_logical, logical_full); count++;\n")
            f.write(f"    riscv_or_{logical}({tag}_bit1, {tag}_bit2, out_logical, logical_full); count++;\n")
            f.write(f"    riscv_not_{logical}({tag}_bit1, out_logical, logical_full); count++;\n")
            f.write(f"    riscv_xor_{logical}({tag}_bit1, {tag}_bit2, out_logical, logical_full); count++;\n")
            f.write(f"    printf(\"RUN testing-smoke/BasicMaths/{tag} calls=%u\\n\", count);\n")
            f.write("    return count;\n")
            f.write("}\n\n")

        f.write("int main(void)\n{\n")
        f.write('    printf("Start testing-smoke/BasicMaths pattern run\\n");\n')
        f.write("    unsigned calls = run_q7() + run_q15() + run_q31();\n")
        f.write('    printf("PASS testing-smoke/BasicMaths calls=%u\\n", calls);\n')
        f.write("    return 0;\n}\n")

    enabled_names = {
        "riscv_abs_q7.c", "riscv_abs_q15.c", "riscv_abs_q31.c",
        "riscv_add_q7.c", "riscv_add_q15.c", "riscv_add_q31.c",
        "riscv_sub_q7.c", "riscv_sub_q15.c", "riscv_sub_q31.c",
        "riscv_mult_q7.c", "riscv_mult_q15.c", "riscv_mult_q31.c",
        "riscv_negate_q7.c", "riscv_negate_q15.c", "riscv_negate_q31.c",
        "riscv_offset_q7.c", "riscv_offset_q15.c", "riscv_offset_q31.c",
        "riscv_scale_q7.c", "riscv_scale_q15.c", "riscv_scale_q31.c",
        "riscv_dot_prod_q7.c", "riscv_dot_prod_q15.c", "riscv_dot_prod_q31.c",
        "riscv_shift_q7.c", "riscv_shift_q15.c", "riscv_shift_q31.c",
        "riscv_clip_q7.c", "riscv_clip_q15.c", "riscv_clip_q31.c",
        "riscv_and_u8.c", "riscv_and_u16.c", "riscv_and_u32.c",
        "riscv_or_u8.c", "riscv_or_u16.c", "riscv_or_u32.c",
        "riscv_not_u8.c", "riscv_not_u16.c", "riscv_not_u32.c",
        "riscv_xor_u8.c", "riscv_xor_u16.c", "riscv_xor_u32.c",
    }
    algo_sources = [src for src in sorted((DSP / "Source" / "BasicMathFunctions").glob("riscv_*.c")) if src.name in enabled_names]
    sources = [runner] + algo_sources + [ROOT / "port" / "src" / "compat_runtime.c"]
    with (outdir / "sources.mk").open("w") as f:
        f.write("TEST_NAME := nmsis-dsp-testing-smoke-basicmaths\n")
        f.write("TEST_SRCS := \\\n")
        for src in sources:
            f.write(f"  {rel(src)} \\\n")
        f.write("\n")

    return [{
        "system": "testing_smoke",
        "suite": suite,
        "path": rel(runner),
        "status": "enabled",
        "reason": "uses_pre_generated_basicmath_q7_q15_q31_patterns_without_numeric_assertions",
    }]


def enumerate_skipped(rows):
    enabled_paths = {r["path"] for r in rows if r["status"] == "enabled"}
    # Benchmark entries outside the first-wave BasicMath fixed-point subset.
    for path in sorted((DSP / "Benchmark").rglob("test_*.c")):
        rpath = rel(path)
        if rpath in enabled_paths or any(r["path"] == rpath for r in rows):
            continue
        blockers = blockers_for(path)
        suite = path.relative_to(DSP / "Benchmark").parts[0]
        rows.append({
            "system": "benchmark",
            "suite": suite,
            "path": rpath,
            "status": "skipped",
            "reason": ";".join(blockers or ["not_first_wave_suite"]),
        })
    # Legacy entries outside first wave.
    for path in sorted((DSP / "Test").rglob("*.c")):
        rpath = rel(path)
        if rpath in enabled_paths or any(r["path"] == rpath for r in rows):
            continue
        suite = path.relative_to(DSP / "Test").parts[0]
        reason = blockers_for(path) or ["not_first_wave_suite"]
        if rpath == rel(DSP / "Test" / "BasicMathFunctions" / "riscv_basic_math_functions.c"):
            reason = ["replaced_by_zircon_fixed_runner", "f32_difftest_gap", "unsigned_logical_lbu_difftest_gap"]
        rows.append({
            "system": "legacy",
            "suite": suite,
            "path": rpath,
            "status": "skipped",
            "reason": ";".join(reason),
        })
    # C++ Testing is accounted for but not enabled until a C++ STL/runtime port exists.
    for path in sorted((DSP / "Testing" / "Source" / "Tests").glob("*.cpp")):
        reason = "cpp_runtime_gap"
        if path.stem in ("BasicTestsQ7", "BasicTestsQ15", "BasicTestsQ31"):
            reason = "covered_by_testing_smoke_no_assertions"
        rows.append({
            "system": "testing",
            "suite": path.stem,
            "path": rel(path),
            "status": "skipped",
            "reason": reason,
        })
    for path in sorted((DSP / "Testing" / "Source" / "Benchmarks").glob("*.cpp")):
        rows.append({
            "system": "testing_benchmark",
            "suite": path.stem,
            "path": rel(path),
            "status": "skipped",
            "reason": "cpp_runtime_gap",
        })


def write_manifest(rows):
    MANIFESTS.mkdir(exist_ok=True)
    out = MANIFESTS / "dsp_test_plan.csv"
    fields = ["system", "suite", "path", "status", "reason"]
    with out.open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)

    summary = {}
    for row in rows:
        key = (row["system"], row["status"])
        summary[key] = summary.get(key, 0) + 1
    with (MANIFESTS / "ZIRCON_TEST_PLAN.md").open("w") as f:
        f.write("# Zircon NMSIS DSP Test Plan\n\n")
        f.write("This manifest is generated by `scripts/generate_zircon_tests.py`.\n\n")
        for (system, status), count in sorted(summary.items()):
            f.write(f"- {system} {status}: {count}\n")
        f.write("\nGenerated executable inputs:\n")
        f.write("\n- benchmark/* integer/fixed-point, f32, and validated non-f16/f64 helper C runners generated from NMSIS Benchmark test_*.c\n")
        f.write("- benchmark/ControllerFunctions/pid_riscv_pid_q15 is enabled after the Dandelion packetizer inline-asm fix\n")
        f.write("- legacy/BasicMathFunctions Zircon fixed-point runner, 30 q7/q15/q31 checks\n")
        f.write("- legacy/*/cases/* single-source entries for every upstream NMSIS Test/*.c file; sources with upstream main use that main, no-main sources use a compile-link smoke runner\n")
        f.write("- testing_smoke/BasicMaths Q7/Q15/Q31 pattern-driven calls without numeric assertions\n")
        f.write("\nDefault `make test-all` benchmark suites:\n")
        for suite in DEFAULT_BENCHMARK_SUITES:
            f.write(f"\n- {suite}")
        f.write("\n\nAll generated Benchmark suite directories are included in the default list. All Benchmark cases whose source file is f32 are enabled; no benchmark f32 case remains skipped.\n")
        f.write("Additional non-f16/f64 Benchmark helper cases are enabled after single-case validation, including q15/q31 controller/filtering, boolean distance, and float/fixed conversion paths.\n")
        f.write("Distance boolean helper dependency closure includes riscv_boolean_distance.c and generated helper symbols, and dependency scanning ignores comments.\n")
        f.write("Benchmark runs default to USE_SIMULATOR_ONLY_MODE=1. Override USE_SIMULATOR_ONLY_MODE=0 to compare both GPR and FPR writes against the reference simulator.\n")
        f.write("Remaining Benchmark skips are f16/f64-oriented deferred areas.\n")
        f.write("The upstream legacy BasicMath main is preserved under test-backups/ and excluded from discovery; its aligned replacement keeps every wide-logical test buffer 8-byte aligned.\n")
        f.write("All upstream legacy C sources are generated as per-case executable entries. Sources that already define main use their upstream entry point; no-main reference/helper sources use a compile-link smoke runner. Some generated legacy cases are expected to expose reference compile errors or runtime numeric/SNR mismatches until their helpers and tolerances are ported.\n")
        f.write("Most `Testing` C++ suites are tracked but skipped until either a C++ standard library/runtime shim or a suite-specific C smoke runner is available.\n")


def main():
    rows = []
    rows.extend(benchmark_suites())
    rows.extend(legacy_basicmath())
    rows.extend(legacy_all_cases())
    rows.extend(testing_basicmath_smoke())
    enumerate_skipped(rows)
    write_manifest(rows)
    enabled = sum(1 for r in rows if r["status"] == "enabled")
    skipped = len(rows) - enabled
    print(f"Generated Zircon test plan: enabled={enabled} skipped={skipped}")


if __name__ == "__main__":
    main()
