#include <stdio.h>
extern void hamming_distance_riscv_hamming_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/hamming_distance_riscv_hamming_distance\n");
    printf("RUN hamming_distance_riscv_hamming_distance\n");
    hamming_distance_riscv_hamming_distance();
    printf("PASS benchmark/DistanceFunctions/hamming_distance_riscv_hamming_distance count=%d\n", 1);
    return 0;
}
