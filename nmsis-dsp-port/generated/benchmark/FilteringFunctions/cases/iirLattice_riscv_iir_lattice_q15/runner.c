#include <stdio.h>
extern void iirLattice_riscv_iir_lattice_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/iirLattice_riscv_iir_lattice_q15\n");
    printf("RUN iirLattice_riscv_iir_lattice_q15\n");
    iirLattice_riscv_iir_lattice_q15();
    printf("PASS benchmark/FilteringFunctions/iirLattice_riscv_iir_lattice_q15 count=%d\n", 1);
    return 0;
}
