#include <stddef.h>
#include <stdint.h>

static uint32_t prng_state = 1U;

void srand(unsigned int seed)
{
    prng_state = seed == 0U ? 1U : seed;
}

int rand(void)
{
    uint32_t value = prng_state;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    prng_state = value;
    return (int)(value & 0x7fffffffU);
}

int abs(int value) { return value < 0 ? -value : value; }
long labs(long value) { return value < 0 ? -value : value; }

