#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/pid_f32/test_data.h"

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

static void zircon_result_zero_f32(float32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++) {
        data[i] = 0.0f;
    }
}

void pid_riscv_pid_f32(void)
{

    volatile int i = 0;

    float32_t pid_f32_output[ARRAY_SIZE_F32];
    riscv_pid_instance_f32 PIDS;
    PIDS.Kp = (float32_t)rand() / RAND_MAX;
    PIDS.Ki = (float32_t)rand() / RAND_MAX;
    PIDS.Kd = (float32_t)rand() / RAND_MAX;
    float32_t target, ival, ee = 0;
    pid_f32_output[0] = 0;

    /* Target value*/
    target = (float32_t)rand() / 0x7fff;
    /* Inital value */
    ival = 0;
    /* Initial value and target value error */
    ee = target - ival;
    /* Initial DSP PID controller function*/
    riscv_pid_init_f32(&PIDS, 1);
    
    zircon_result_zero_f32(pid_f32_output, (uint32_t)(sizeof(pid_f32_output) / sizeof(pid_f32_output[0])));
BENCH_START(riscv_pid_f32);
    for (i = 1; i < ARRAY_SIZE_F32; i++) {
        pid_f32_output[i] = riscv_pid_f32(&PIDS, ee);
        ee = target - pid_f32_output[i - 1];
    }
    BENCH_END(riscv_pid_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pid_f32_output, (uint32_t)sizeof(pid_f32_output));
    printf("@@RESULT@@ case=pid_riscv_pid_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}