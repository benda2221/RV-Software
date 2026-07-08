#include <stdio.h>
extern void iirLattice_riscv_iir_lattice_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/iirLattice_riscv_iir_lattice_f32\n");
    printf("RUN iirLattice_riscv_iir_lattice_f32\n");
    iirLattice_riscv_iir_lattice_f32();
    printf("PASS benchmark/FilteringFunctions/iirLattice_riscv_iir_lattice_f32 count=%d\n", 1);
    return 0;
}
