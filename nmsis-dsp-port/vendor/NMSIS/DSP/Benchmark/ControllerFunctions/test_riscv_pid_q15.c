#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/pid_q15/test_data.h"

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


void pid_riscv_pid_q15(void)
{

    volatile int i = 0;

    q15_t pid_q15_output[ARRAY_SIZE_Q15];
    riscv_pid_instance_f32 PIDS;
    riscv_pid_instance_q15 PIDS_q15;
    PIDS.Kp = (float32_t)rand() / RAND_MAX;
    PIDS.Ki = (float32_t)rand() / RAND_MAX;
    PIDS.Kd = (float32_t)rand() / RAND_MAX;
    riscv_float_to_q15(&PIDS.Kp, &PIDS_q15.Kp, 1);
    riscv_float_to_q15(&PIDS.Ki, &PIDS_q15.Ki, 1);
    riscv_float_to_q15(&PIDS.Kd, &PIDS_q15.Kd, 1);
    q15_t target, ival, ee = 0;
    pid_q15_output[0] = 0;

    /* Target value*/
    target = (q15_t)(rand() % 0x7fff);
    /* Inital value */
    ival = 0;
    /* Initial value and target value error */
    ee = target - ival;
    /* Initial DSP PID controller function*/
    riscv_pid_init_q15(&PIDS_q15, 0);
    BENCH_START(riscv_pid_q15);
    for (i = 1; i < ARRAY_SIZE_Q15; i++) {
        pid_q15_output[i] = riscv_pid_q15(&PIDS_q15, ee);
        ee = target - pid_q15_output[i - 1];
    }
    BENCH_END(riscv_pid_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pid_q15_output, (uint32_t)sizeof(pid_q15_output));
    printf("@@RESULT@@ case=pid_riscv_pid_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}
