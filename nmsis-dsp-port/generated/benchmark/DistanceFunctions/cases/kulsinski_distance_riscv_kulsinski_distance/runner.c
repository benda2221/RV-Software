#include <stdio.h>
extern void kulsinski_distance_riscv_kulsinski_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/kulsinski_distance_riscv_kulsinski_distance\n");
    printf("RUN kulsinski_distance_riscv_kulsinski_distance\n");
    kulsinski_distance_riscv_kulsinski_distance();
    printf("PASS benchmark/DistanceFunctions/kulsinski_distance_riscv_kulsinski_distance count=%d\n", 1);
    return 0;
}
