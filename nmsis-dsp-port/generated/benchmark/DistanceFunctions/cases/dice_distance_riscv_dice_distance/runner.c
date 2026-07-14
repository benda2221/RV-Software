#include <stdio.h>
extern void dice_distance_riscv_dice_distance(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/dice_distance_riscv_dice_distance\n");
    printf("RUN dice_distance_riscv_dice_distance\n");
    dice_distance_riscv_dice_distance();
    printf("PASS benchmark/DistanceFunctions/dice_distance_riscv_dice_distance count=%d\n", 1);
    return 0;
}
