#include <stddef.h>
#include <stdint.h>

static uint32_t prng_state = 1U;
static unsigned char heap_area[256 * 1024] __attribute__((aligned(16)));
static size_t heap_offset;

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
    prng_state = value == 0U ? 1U : value;
    return (int)(prng_state & 0x7fffffffU);
}

int abs(int value)
{
    return value < 0 ? -value : value;
}

long labs(long value)
{
    return value < 0 ? -value : value;
}

void *malloc(size_t size)
{
    if (size == 0) {
        size = 1;
    }
    size = (size + 15U) & ~(size_t)15U;
    if (heap_offset + size > sizeof(heap_area)) {
        return NULL;
    }
    void *ptr = &heap_area[heap_offset];
    heap_offset += size;
    return ptr;
}

void free(void *pointer)
{
    (void)pointer;
}

double log10(double value)
{
    (void)value;
    return 0.0;
}
