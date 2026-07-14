#include <stdio.h>
extern void sokalmichener_distance_riscv_sokalmichener_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/sokalmichener_distance_riscv_sokalmichener_distance\n");
    printf("RUN sokalmichener_distance_riscv_sokalmichener_distance\n");
    sokalmichener_distance_riscv_sokalmichener_distance();
    printf("PASS benchmark/DistanceFunctions/sokalmichener_distance_riscv_sokalmichener_distance count=%d\n", 1);
    return 0;
}
