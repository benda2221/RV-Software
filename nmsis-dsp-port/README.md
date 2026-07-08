# NMSIS DSP Port for Zircon-VLIW

This project runs portable NMSIS-DSP algorithms on the Zircon bare-metal
runtime with the Dandelion LLVM backend. It intentionally excludes `libm`,
random input generation, and cycle-counter benchmarking during the functional
porting phase.

## Current Coverage

- Q31 Biquad cascade DF1 initialization and processing
- Q7/Q15/Q31 absolute value
- Q7/Q15/Q31 addition and subtraction
- Q7/Q15/Q31 negation
- Saturation edge cases and deterministic PASS/FAIL reporting

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

Build and run on ZirconSim:

```sh
make clean image
make run
```

The compatibility boundary is under `include/dsp/`. Keep processor runtime,
compiler intrinsics, and test reporting there instead of editing imported
NMSIS sources.

## Next Integer Batches

1. BasicMath multiply, scale, offset, clip, dot product, and bitwise functions.
2. SupportFunctions fixed-point conversion, copy, fill, sort, and weighted sum.
3. Fixed-point filtering, transform, matrix, statistics, and interpolation.
4. Deterministic test generation and one executable per function group.

Floating-point functions that require missing math-library routines remain
deferred. Performance measurement remains disabled until functional coverage
is stable.
