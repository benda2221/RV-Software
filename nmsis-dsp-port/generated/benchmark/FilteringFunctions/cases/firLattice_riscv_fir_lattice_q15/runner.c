#include <stdio.h>
extern void firLattice_riscv_fir_lattice_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_q15\n");
    printf("RUN firLattice_riscv_fir_lattice_q15\n");
    firLattice_riscv_fir_lattice_q15();
    printf("PASS benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_q15 count=%d\n", 1);
    return 0;
}
