#!/bin/sh
set -eu

NMSIS_ROOT=${NMSIS_ROOT:-/home/zhangfulin/RISCV-VLIW/NMSIS/NMSIS}
DEST=$(CDPATH= cd -- "$(dirname -- "$0")/../vendor/NMSIS/DSP" && pwd)

for directory in Include PrivateInclude Source Benchmark Test Testing Examples; do
    mkdir -p "$DEST/$directory"
    cp -a "$NMSIS_ROOT/DSP/$directory/." "$DEST/$directory/"
done

printf 'Synchronized complete NMSIS DSP tree from %s\n' "$NMSIS_ROOT"
