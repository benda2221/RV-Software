#!/bin/sh
set -eu
NMSIS_ROOT=${NMSIS_ROOT:-/home/zhangfulin/RISCV-VLIW/NMSIS/NMSIS}
DEST=$(CDPATH= cd -- "$(dirname -- "$0")/../src" && pwd)
copy_source() {
    source_path=$1
    cp "$NMSIS_ROOT/DSP/Source/$source_path" "$DEST/$(basename "$source_path")"
}
copy_source FilteringFunctions/riscv_biquad_cascade_df1_init_q31.c
copy_source FilteringFunctions/riscv_biquad_cascade_df1_q31.c
for operation in abs add sub negate; do
    for format in q7 q15 q31; do
        copy_source "BasicMathFunctions/riscv_${operation}_${format}.c"
    done
done
printf 'Synchronized NMSIS sources from %s\n' "$NMSIS_ROOT"
