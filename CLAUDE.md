# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

RV-Software is a RISC-V Software and Compiler Environment for CPU testing. It is a collection of test programs, benchmarks, and DSP algorithms targeting the **RV32IM** architecture (with Zicsr and Zifencei extensions), designed to validate and benchmark RISC-V 32-bit processors.

## Build System

There is **no top-level Makefile**. Each test program lives in its own directory and has its own Makefile that includes `base-port/Makefile` as the shared build infrastructure.

### Required environment

- **Toolchain**: LLVM (`clang`, `ld.lld`, `llvm-ar`, `llvm-objdump`, `llvm-objcopy`) — no `CROSS_COMPILE` prefix needed
- **Target**: `--target=riscv32`, `-march=rv32im_zicsr_zifencei -mabi=ilp32`
- **SIM_PATH**: Each Makefile sets this to the simulator directory (`../../` by default)

### Common Makefile targets (run from individual test directories)

```sh
make               # Build ELF binary (default: image)
make image         # Build ELF, disassembly (.txt), and binary (.bin)
make run           # Build and run on simulator
make gdb           # Build and launch GDB session on simulator
make clean         # Remove ./build/
make clean-all     # Remove ./build/ and base-port library builds
```

### Building a benchmark (e.g., coremark)

```sh
cd coremark && make
# Output: build/coremark-riscv32.elf, .bin, .txt
```

### Building and running all functional tests

```sh
cd functest && make run
# Builds each src/*.c as a separate binary, runs each, prints ACCEPT/FAILED summary
```

### Building the base libraries manually

```sh
cd base-port/base && make libkernel
cd base-port/tool && make libkernel
```

Libraries output to `base-port/base/build/libbase.a` and `base-port/tool/build/libtool.a`.

### Adding a new test program

Create a directory with a Makefile following this pattern:

```makefile
NAMES = mytest
SRCS  = src/mytest.c
BASE_PORT = $(abspath ../base-port)
SIM_PATH  = $(abspath ../../)
include $(BASE_PORT)/Makefile
```

## Architecture

### Layer structure

```
test program (e.g., coremark/, functest/, DSP/)
    ↓ links against
base-port/base/   — platform abstraction (boot, MMIO devices, I/O events)
base-port/tool/   — minimal C stdlib (printf, string, 64-bit arithmetic)
    ↓ uses
base-port/script/ — build rules (base.mk, riscv32.mk) + linker.ld
```

### Boot and memory layout

- Entry point: `_start` in `base-port/base/src/start.S` — initializes stack, clears BSS, calls `main`
- Program base: `0x80000000`
- Stack: 64 KB (defined in `linker.ld`, recently increased to `0x10000` for FFT/Cholesky)
- MMIO devices: base at `0xa0000000` (UART, Timer, Input, GPU, Disk)

### Device access model

All device I/O is **MMIO-only** (no DMA, no interrupts). Device register addresses and `inb`/`outb` accessors are defined in `base-port/base/include/dev-mmio.h`. Higher-level event-based wrappers are in `base-port/base/src/ioe.c`.

### Functional test validation pattern

Each `functest/src/*.c` uses the `check()` macro from `include/trap.h`, which triggers a trap/halt on failure. The functest Makefile runs each binary via the simulator and reports ACCEPT/FAILED based on exit status.

### picotest (instruction-level tests)

`picotest/` contains 56 `.S` assembly files, one per RISC-V instruction, using macros from `include/test_macros.h` and `include/test_macros_csr.h`. These validate individual instruction behavior at the ISA level.

## Key compiler flags

| Flag | Purpose |
|------|---------|
| `-fno-builtin` | Use custom stdlib implementations in `base-port/tool/` |
| `-fno-stack-protector` | No stack canary (bare metal) |
| `-fdata-sections -ffunction-sections` | Enable linker dead-code elimination (`--gc-sections`) |
| `-Os` | Optimize for size |
| `-Wall -Werror` | All warnings treated as errors (in test programs) |
