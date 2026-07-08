#include <stdio.h>
extern void firLattice_riscv_fir_lattice_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_f32\n");
    printf("RUN firLattice_riscv_fir_lattice_f32\n");
    firLattice_riscv_fir_lattice_f32();
    printf("PASS benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_f32 count=%d\n", 1);
    return 0;
}
