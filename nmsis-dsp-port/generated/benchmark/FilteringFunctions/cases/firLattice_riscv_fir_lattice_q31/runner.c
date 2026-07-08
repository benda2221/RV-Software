#include <stdio.h>
extern void firLattice_riscv_fir_lattice_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_q31\n");
    printf("RUN firLattice_riscv_fir_lattice_q31\n");
    firLattice_riscv_fir_lattice_q31();
    printf("PASS benchmark/FilteringFunctions/firLattice_riscv_fir_lattice_q31 count=%d\n", 1);
    return 0;
}
