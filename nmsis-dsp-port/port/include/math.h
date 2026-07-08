#ifndef ZIRCON_PORT_MATH_H
#define ZIRCON_PORT_MATH_H

#define PI 3.14159265358979323846
#define M_PI PI
#define NAN (__builtin_nanf(""))
#define INFINITY (__builtin_inff())

static inline float fabsf(float value) { return __builtin_fabsf(value); }
static inline double fabs(double value) { return __builtin_fabs(value); }
static inline int isnan(double value) { return __builtin_isnan(value); }
static inline int isinf(double value) { return __builtin_isinf(value); }

float sqrtf(float value);
double sqrt(double value);
float sinf(float value);
double sin(double value);
float cosf(float value);
double cos(double value);
float logf(float value);
double log(double value);
double log10(double value);
float expf(float value);
double exp(double value);
float powf(float base, float exponent);
double pow(double base, double exponent);
float floorf(float value);
double floor(double value);
float ceilf(float value);
double ceil(double value);
float atan2f(float y, float x);
double atan2(double y, double x);

#endif
