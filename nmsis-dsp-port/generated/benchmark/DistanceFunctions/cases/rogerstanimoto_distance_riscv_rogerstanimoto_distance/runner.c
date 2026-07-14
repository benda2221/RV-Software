#include <stdio.h>
extern void rogerstanimoto_distance_riscv_rogerstanimoto_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/rogerstanimoto_distance_riscv_rogerstanimoto_distance\n");
    printf("RUN rogerstanimoto_distance_riscv_rogerstanimoto_distance\n");
    rogerstanimoto_distance_riscv_rogerstanimoto_distance();
    printf("PASS benchmark/DistanceFunctions/rogerstanimoto_distance_riscv_rogerstanimoto_distance count=%d\n", 1);
    return 0;
}
