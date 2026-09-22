#ifndef ZIRCON_PORT_MATH_H
#define ZIRCON_PORT_MATH_H

#define PI 3.14159265358979323846f
#define M_PI PI
#define NAN (__builtin_nanf(""))
#define INFINITY (__builtin_inff())
#define signbit(value) __builtin_signbit(value)

static inline float fabsf(float value) { return __builtin_fabsf(value); }
#if defined(ZIRCON_ENABLE_FLOAT64)
static inline double fabs(double value) { return __builtin_fabs(value); }
#endif
#define isnan(value) __builtin_isnan(value)
#define isinf(value) __builtin_isinf(value)

float sqrtf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double sqrt(double value);
#endif
float sinf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double sin(double value);
#endif
float cosf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double cos(double value);
#endif
float logf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double log(double value);
double log10(double value);
#endif
float log10f(float value);
float expf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double exp(double value);
#endif
float tanhf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double tanh(double value);
#endif
float powf(float base, float exponent);
#if defined(ZIRCON_ENABLE_FLOAT64)
double pow(double base, double exponent);
#endif
float floorf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double floor(double value);
#endif
float ceilf(float value);
#if defined(ZIRCON_ENABLE_FLOAT64)
double ceil(double value);
#endif
float atan2f(float y, float x);
#if defined(ZIRCON_ENABLE_FLOAT64)
double atan2(double y, double x);
#endif

#endif
