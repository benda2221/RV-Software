#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/pid_q31/test_data.h"

BENCH_DECLARE_VAR();

static uint32_t zircon_result_hash_combine(uint32_t hash, const void *data, uint32_t length)
{
    const uint8_t *bytes = (const uint8_t *)data;

    for (uint32_t i = 0; i < length; i++) {
        hash ^= bytes[i];
        hash *= 16777619u;
    }

    return hash;
}


void pid_riscv_pid_q31(void)
{

    volatile int i = 0;

    float32_t pid_q31_output[ARRAY_SIZE_Q31];
    riscv_pid_instance_f32 PIDS;
    riscv_pid_instance_q31 PIDS_q31;
    PIDS.Kp = (float32_t)rand() / RAND_MAX;
    PIDS.Ki = (float32_t)rand() / RAND_MAX;
    PIDS.Kd = (float32_t)rand() / RAND_MAX;
    riscv_float_to_q31(&PIDS.Kp, &PIDS_q31.Kp, 1);
    riscv_float_to_q31(&PIDS.Ki, &PIDS_q31.Ki, 1);
    riscv_float_to_q31(&PIDS.Kd, &PIDS_q31.Kd, 1);
    q31_t target, ival, ee = 0;
    pid_q31_output[0] = 0;

    /* Target value*/
    target = (q31_t)rand();
    /* Inital value */
    ival = 0;
    /* Initial value and target value error */
    ee = target - ival;
    /* Initial DSP PID controller function*/
    riscv_pid_init_q31(&PIDS_q31, 1);
    BENCH_START(riscv_pid_q31);
    for (i = 1; i < ARRAY_SIZE_Q31; i++) {
        pid_q31_output[i] = riscv_pid_q31(&PIDS_q31, ee);
        ee = target - pid_q31_output[i - 1];
    }
    BENCH_END(riscv_pid_q31);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pid_q31_output, (uint32_t)sizeof(pid_q31_output));
    printf("@@RESULT@@ case=pid_riscv_pid_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
