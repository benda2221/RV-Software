#include <stdio.h>
extern void sokalsneath_distance_riscv_sokalsneath_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/sokalsneath_distance_riscv_sokalsneath_distance\n");
    printf("RUN sokalsneath_distance_riscv_sokalsneath_distance\n");
    sokalsneath_distance_riscv_sokalsneath_distance();
    printf("PASS benchmark/DistanceFunctions/sokalsneath_distance_riscv_sokalsneath_distance count=%d\n", 1);
    return 0;
}
