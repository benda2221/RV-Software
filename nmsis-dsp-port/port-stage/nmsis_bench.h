#ifndef ZIRCON_NMSIS_BENCH_H
#define ZIRCON_NMSIS_BENCH_H

#include <stdio.h>

#define BENCH_DECLARE_VAR() static volatile unsigned long zircon_bench_error
#define BENCH_INIT() do { zircon_bench_error = 0; } while (0)
#define BENCH_RESET(proc) do { zircon_bench_error = 0; } while (0)
#define BENCH_START(proc) do { zircon_bench_error = 0; } while (0)
#define BENCH_SAMPLE(proc) do { } while (0)
#define BENCH_END(proc) do { } while (0)
#define BENCH_STOP(proc) do { } while (0)
#define BENCH_STAT(proc) do { } while (0)
#define BENCH_GET_USECYC() 0UL
#define BENCH_GET_SUMCYC() 0UL
#define BENCH_GET_LPCNT() 0UL
#define BENCH_ERROR(proc) do { zircon_bench_error = 1; } while (0)
#define BENCH_STATUS(proc) do { \
    printf("%s %s\n", zircon_bench_error ? "FAIL" : "PASS", #proc); \
} while (0)

#define NMSIS_TEST_PASS() do { printf("PASS\n"); } while (0)
#define NMSIS_TEST_FAIL() do { printf("FAIL\n"); } while (0)

#endif
