#include <stdio.h>
extern void quaternionProductSingle_riscv_quaternion_product_single_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionProductSingle_riscv_quaternion_product_single_f32\n");
    printf("RUN quaternionProductSingle_riscv_quaternion_product_single_f32\n");
    quaternionProductSingle_riscv_quaternion_product_single_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionProductSingle_riscv_quaternion_product_single_f32 count=%d\n", 1);
    return 0;
}
