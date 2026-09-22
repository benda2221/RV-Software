# NMSIS DSP Port for Zircon-VLIW

This project runs portable NMSIS-DSP algorithms on the Zircon bare-metal
runtime with the Dandelion LLVM backend. The current harness focuses on
functional execution of imported NMSIS C benchmark/test sources; cycle-accurate
benchmark measurement is still outside this port.

## Current Coverage

- Generated NMSIS Benchmark C runners for all default benchmark suite directories
- All Benchmark `f32` cases enabled; `benchmark` has no remaining `f32` skipped entries
- Validated non-f16/f64 Benchmark helper cases enabled, including q15/q31 controller/filtering, boolean distance, and float/fixed conversion cases
- Fixed-point/integer Benchmark cases that are buildable with the current C runtime
- Legacy BasicMath fixed-point runner, covering 30 q7/q15/q31 checks
- Per-case generated entries for every upstream legacy `Test/**/*.c` source;
  sources with upstream `main` use that entry point, while no-main reference
  helpers use a compile-link smoke runner
- BasicMaths Testing smoke runner for Q7/Q15/Q31 pattern-driven calls

Algorithm files in `src/riscv_*.c` are copied unchanged from NMSIS. Refresh
them after an NMSIS update with:

```sh
sh scripts/sync_nmsis_sources.sh
```

The upstream NMSIS DSP test programs, benchmark programs, C++ pattern test
framework, pattern data, benchmark data, and example programs are staged under
`vendor/NMSIS/DSP/{Benchmark,Test,Testing,Examples}`. Refresh those staged
test assets with:

```sh
sh scripts/sync_nmsis_tests.sh
python3 port-stage/generate_manifest.py
```

Generate, build, and run generated tests on ZirconSim:

```sh
make generate-tests
make TEST_SYSTEM=benchmark SUITE=FastMathFunctions run
make TEST_SYSTEM=benchmark SUITE=SVMFunctions run
make TEST_SYSTEM=legacy SUITE=BayesianFunctions TEST_CASE=riscv_bayesian run
make test-all
```

`nmsis-dsp-port` defaults to `USE_SIMULATOR_ONLY_MODE=1` so f32 Benchmark
runners avoid the current F-instruction difftest path. Override it explicitly
when the difftest path is the target:

```sh
USE_SIMULATOR_ONLY_MODE=0 make TEST_SYSTEM=benchmark SUITE=FastMathFunctions run
```

Reproduce the currently skipped backend-codegen failure case with:

```sh
make TEST_SYSTEM=benchmark SUITE=ControllerFunctions TEST_CASE=pid_riscv_pid_q15 clean run
```

The compatibility boundary is under `include/dsp/`. Keep processor runtime,
compiler intrinsics, and test reporting there instead of editing imported
NMSIS sources. Minimal math-library compatibility for Benchmark f32 execution
lives in `port/include/math.h` and `port/src/compat_runtime.c`; it is intended
to make the benchmark runners link and execute, not to replace a full libm.
The target is currently RV32IMF (`-march=rv32imf`, LLC `+m,+f,-d`); f32
helpers must use float constants/functions, while f64 cases remain skipped.

## Remaining Deferred Areas

- Benchmark `f16`, `f64`, RVV/vector, and aggregate translation-unit cases
- `Benchmark/ControllerFunctions/test_riscv_pid_q15.c`, which currently trips `LLVM ERROR: Dandelion VLIW instruction has no legal slot` in `RISCV Packet Padding`
- Legacy per-case entries are generated but remain outside default `test-all`;
  several are expected to fail on reference-source compile issues or runtime
  numeric/SNR mismatches until those helpers and tolerances are ported
- C++ Testing and Testing Benchmark suites until a C++ runtime/STL shim or
  suite-specific C smoke runner is available
- Numeric reference checking for generated Benchmark runners; current generated
  Benchmark runners execute cases and report deterministic hashes/PASS markers
- Cycle-counter performance measurement
