#include <stdio.h>
extern void russellrao_distance_riscv_russellrao_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/russellrao_distance_riscv_russellrao_distance\n");
    printf("RUN russellrao_distance_riscv_russellrao_distance\n");
    russellrao_distance_riscv_russellrao_distance();
    printf("PASS benchmark/DistanceFunctions/russellrao_distance_riscv_russellrao_distance count=%d\n", 1);
    return 0;
}
