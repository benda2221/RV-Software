#include <stdio.h>
extern void jaccard_distance_riscv_jaccard_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/jaccard_distance_riscv_jaccard_distance\n");
    printf("RUN jaccard_distance_riscv_jaccard_distance\n");
    jaccard_distance_riscv_jaccard_distance();
    printf("PASS benchmark/DistanceFunctions/jaccard_distance_riscv_jaccard_distance count=%d\n", 1);
    return 0;
}
