#include <stdio.h>
extern void cfft_riscv_cfft_q15(void);
extern void cfft_riscv_cfft_q31(void);
extern void cfft_riscv_cfft_radix2_f32(void);
extern void cfft_riscv_cfft_radix2_q15(void);
extern void cfft_riscv_cfft_radix2_q31(void);
extern void cfft_riscv_cfft_radix4_f32(void);
extern void cfft_riscv_cfft_radix4_q15(void);
extern void cfft_riscv_cfft_radix4_q31(void);
extern void dct4_riscv_dct4_f32(void);
extern void dct4_riscv_dct4_q15(void);
extern void dct4_riscv_dct4_q31(void);
extern void rfft_riscv_rfft_f32(void);
extern void rfft_riscv_rfft_q15(void);
extern void rfft_riscv_rfft_q31(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions\n");
    printf("RUN cfft_riscv_cfft_q15\n");
    cfft_riscv_cfft_q15();
    printf("RUN cfft_riscv_cfft_q31\n");
    cfft_riscv_cfft_q31();
    printf("RUN cfft_riscv_cfft_radix2_f32\n");
    cfft_riscv_cfft_radix2_f32();
    printf("RUN cfft_riscv_cfft_radix2_q15\n");
    cfft_riscv_cfft_radix2_q15();
    printf("RUN cfft_riscv_cfft_radix2_q31\n");
    cfft_riscv_cfft_radix2_q31();
    printf("RUN cfft_riscv_cfft_radix4_f32\n");
    cfft_riscv_cfft_radix4_f32();
    printf("RUN cfft_riscv_cfft_radix4_q15\n");
    cfft_riscv_cfft_radix4_q15();
    printf("RUN cfft_riscv_cfft_radix4_q31\n");
    cfft_riscv_cfft_radix4_q31();
    printf("RUN dct4_riscv_dct4_f32\n");
    dct4_riscv_dct4_f32();
    printf("RUN dct4_riscv_dct4_q15\n");
    dct4_riscv_dct4_q15();
    printf("RUN dct4_riscv_dct4_q31\n");
    dct4_riscv_dct4_q31();
    printf("RUN rfft_riscv_rfft_f32\n");
    rfft_riscv_rfft_f32();
    printf("RUN rfft_riscv_rfft_q15\n");
    rfft_riscv_rfft_q15();
    printf("RUN rfft_riscv_rfft_q31\n");
    rfft_riscv_rfft_q31();
    printf("PASS benchmark/TransformFunctions count=%d\n", 14);
    return 0;
}
