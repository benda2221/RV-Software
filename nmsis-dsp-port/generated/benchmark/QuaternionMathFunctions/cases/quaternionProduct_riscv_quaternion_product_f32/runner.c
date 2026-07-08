#include <stdio.h>
extern void quaternionProduct_riscv_quaternion_product_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionProduct_riscv_quaternion_product_f32\n");
    printf("RUN quaternionProduct_riscv_quaternion_product_f32\n");
    quaternionProduct_riscv_quaternion_product_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionProduct_riscv_quaternion_product_f32 count=%d\n", 1);
    return 0;
}
