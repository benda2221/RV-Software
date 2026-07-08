#include <stdio.h>
extern void braycurtis_distance_riscv_braycurtis_distance_f32(void);
extern void canberra_distance_riscv_canberra_distance_f32(void);
extern void chebyshev_distance_riscv_chebyshev_distance_f32(void);
extern void cityblock_distance_riscv_cityblock_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions\n");
    printf("RUN braycurtis_distance_riscv_braycurtis_distance_f32\n");
    braycurtis_distance_riscv_braycurtis_distance_f32();
    printf("RUN canberra_distance_riscv_canberra_distance_f32\n");
    canberra_distance_riscv_canberra_distance_f32();
    printf("RUN chebyshev_distance_riscv_chebyshev_distance_f32\n");
    chebyshev_distance_riscv_chebyshev_distance_f32();
    printf("RUN cityblock_distance_riscv_cityblock_distance_f32\n");
    cityblock_distance_riscv_cityblock_distance_f32();
    printf("PASS benchmark/DistanceFunctions count=%d\n", 4);
    return 0;
}
