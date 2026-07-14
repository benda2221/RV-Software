#include <stdio.h>
extern void yule_distance_riscv_yule_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/yule_distance_riscv_yule_distance\n");
    printf("RUN yule_distance_riscv_yule_distance\n");
    yule_distance_riscv_yule_distance();
    printf("PASS benchmark/DistanceFunctions/yule_distance_riscv_yule_distance count=%d\n", 1);
    return 0;
}
