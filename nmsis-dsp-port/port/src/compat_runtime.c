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

static float zircon_wrap_pi(float value)
{
    const float two_pi = 6.2831853071795864769f;
    const float pi = 3.1415926535897932385f;
    while (value > pi) {
        value -= two_pi;
    }
    while (value < -pi) {
        value += two_pi;
    }
    return value;
}

float sqrtf(float value)
{
    if (value <= 0.0f) {
        return 0.0f;
    }
    float x = value > 1.0f ? value : 1.0f;
    for (int i = 0; i < 10; i++) {
        x = 0.5f * (x + value / x);
    }
    return x;
}

double sqrt(double value)
{
    return (double)sqrtf((float)value);
}

float expf(float value)
{
    if (value > 40.0f) {
        value = 40.0f;
    } else if (value < -40.0f) {
        value = -40.0f;
    }

    int scale = 0;
    while (value > 1.0f) {
        value -= 1.0f;
        scale++;
    }
    while (value < -1.0f) {
        value += 1.0f;
        scale--;
    }

    float term = 1.0f;
    float result = 1.0f;
    for (int i = 1; i <= 12; i++) {
        term *= value / (float)i;
        result += term;
    }

    const float e = 2.7182818284590452354f;
    while (scale > 0) {
        result *= e;
        scale--;
    }
    while (scale < 0) {
        result /= e;
        scale++;
    }
    return result;
}

double exp(double value)
{
    return (double)expf((float)value);
}

float tanhf(float value)
{
    if (value > 8.0f) {
        return 1.0f;
    }
    if (value < -8.0f) {
        return -1.0f;
    }
    float e2x = expf(2.0f * value);
    return (e2x - 1.0f) / (e2x + 1.0f);
}

double tanh(double value)
{
    return (double)tanhf((float)value);
}

float logf(float value)
{
    if (value <= 0.0f) {
        return -3.402823466e38f;
    }

    const float ln2 = 0.6931471805599453094f;
    int scale = 0;
    while (value > 1.5f) {
        value *= 0.5f;
        scale++;
    }
    while (value < 0.75f) {
        value *= 2.0f;
        scale--;
    }

    float y = (value - 1.0f) / (value + 1.0f);
    float y2 = y * y;
    float term = y;
    float result = 0.0f;
    for (int n = 1; n <= 19; n += 2) {
        result += term / (float)n;
        term *= y2;
    }
    return 2.0f * result + (float)scale * ln2;
}

double log(double value)
{
    return (double)logf((float)value);
}

double log10(double value)
{
    return (double)(logf((float)value) * 0.4342944819032518f);
}

float powf(float base, float exponent)
{
    if (base <= 0.0f) {
        return 0.0f;
    }
    return expf(exponent * logf(base));
}

double pow(double base, double exponent)
{
    return (double)powf((float)base, (float)exponent);
}

float sinf(float value)
{
    value = zircon_wrap_pi(value);
    float x2 = value * value;
    float term = value;
    float result = value;
    term *= -x2 / 6.0f;
    result += term;
    term *= -x2 / 20.0f;
    result += term;
    term *= -x2 / 42.0f;
    result += term;
    term *= -x2 / 72.0f;
    result += term;
    term *= -x2 / 110.0f;
    result += term;
    return result;
}

double sin(double value)
{
    return (double)sinf((float)value);
}

float cosf(float value)
{
    value = zircon_wrap_pi(value);
    float x2 = value * value;
    float term = 1.0f;
    float result = 1.0f;
    term *= -x2 / 2.0f;
    result += term;
    term *= -x2 / 12.0f;
    result += term;
    term *= -x2 / 30.0f;
    result += term;
    term *= -x2 / 56.0f;
    result += term;
    term *= -x2 / 90.0f;
    result += term;
    return result;
}

double cos(double value)
{
    return (double)cosf((float)value);
}

float floorf(float value)
{
    int truncated = (int)value;
    if ((float)truncated > value) {
        truncated--;
    }
    return (float)truncated;
}

double floor(double value)
{
    return (double)floorf((float)value);
}

float ceilf(float value)
{
    int truncated = (int)value;
    if ((float)truncated < value) {
        truncated++;
    }
    return (float)truncated;
}

double ceil(double value)
{
    return (double)ceilf((float)value);
}

float atan2f(float y, float x)
{
    const float pi = 3.1415926535897932385f;
    if (x == 0.0f) {
        return y >= 0.0f ? pi * 0.5f : -pi * 0.5f;
    }
    float z = y / x;
    float az = z < 0.0f ? -z : z;
    float atan;
    if (az < 1.0f) {
        atan = z / (1.0f + 0.28f * z * z);
    } else {
        atan = pi * 0.5f - z / (z * z + 0.28f);
        if (z < 0.0f) {
            atan -= pi;
        }
    }
    if (x < 0.0f) {
        atan += y >= 0.0f ? pi : -pi;
    }
    return atan;
}

double atan2(double y, double x)
{
    return (double)atan2f((float)y, (float)x);
}
