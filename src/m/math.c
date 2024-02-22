#include <math.h>
#include <stdlib.h>

#include "src/wasm.h"

#if !defined(__has_builtin)
#define __has_builtin(x) 0
#endif

WASM_IMPORT("math", "trunc") double _trunc_impl(double);
WASM_IMPORT("math", "round") double _round_impl(double);
WASM_IMPORT("math", "floor") double _floor_impl(double);
WASM_IMPORT("math", "ceil") double _ceil_impl(double);
WASM_IMPORT("math", "sqrt") double _sqrt_impl(double);

WASM_IMPORT("math", "log") double _log_impl(double);
WASM_IMPORT("math", "log2") double _log2_impl(double);
WASM_IMPORT("math", "log10") double _log10_impl(double);
WASM_IMPORT("math", "exp") double _exp_impl(double);
WASM_IMPORT("math", "pow") double _pow_impl(double, double);

WASM_IMPORT("math", "sin") double _sin_impl(double);
WASM_IMPORT("math", "cos") double _cos_impl(double);
WASM_IMPORT("math", "tan") double _tan_impl(double);
WASM_IMPORT("math", "asin") double _asin_impl(double);
WASM_IMPORT("math", "acos") double _acos_impl(double);
WASM_IMPORT("math", "atan") double _atan_impl(double);
WASM_IMPORT("math", "atan2") double _atan2_impl(double, double);

WASM_IMPORT("math", "sinh") double _sinh_impl(double);
WASM_IMPORT("math", "cosh") double _cosh_impl(double);
WASM_IMPORT("math", "tanh") double _tanh_impl(double);
WASM_IMPORT("math", "asinh") double _asinh_impl(double);
WASM_IMPORT("math", "acosh") double _acosh_impl(double);
WASM_IMPORT("math", "atanh") double _atanh_impl(double);

WASM_IMPORT("math", "random") double _random_impl();

// Double precision intrinsics

double trunc(double x) {
#if __has_builtin(__builtin_trunc)
    return __builtin_trunc(x);
#else
    return _trunc_impl(x);
#endif
}

double round(double x) {
#if __has_builtin(__builtin_round)
    return __builtin_round(x);
#else
    return _round_impl(x);
#endif
}

double floor(double x) {
#if __has_builtin(__builtin_floor)
    return __builtin_floor(x);
#else
    return _floor_impl(x);
#endif
}

double ceil(double x) {
#if __has_builtin(__builtin_ceil)
    return __builtin_ceil(x);
#else
    return _ceil_impl(x);
#endif
}

double sqrt(double x) {
#if __has_builtin(__builtin_sqrt)
    return __builtin_sqrt(x);
#else
    return _sqrt_impl(x);
#endif
}

double fabs(double x) {
#if __has_builtin(__builtin_fabs)
    return __builtin_fabs(x);
#else
    return x < 0 ? -x : x;
#endif
}

double fmod(double x, double y) {
#if __has_builtin(__builtin_fmod)
    return __builtin_fmod(x, y);
#else
    return x - y * (int)(x / y);
#endif
}

double modf(double value, double* intpart) {
#if __has_builtin(__builtin_modf)
    return __builtin_modf(value, intpart);
#else
    *intpart = trunc(value);
    return value - *intpart;
#endif
}

double ldexp(double x, int exp) {
#if __has_builtin(__builtin_ldexp)
    return __builtin_ldexp(x, exp);
#else
    return x * pow(2, exp);
#endif
}

// Double precision functions imported from javascript

double log(double x) { return _log_impl(x); }
double log2(double x) { return _log2_impl(x); }
double log10(double x) { return _log_impl(x); }
double exp(double x) { return _exp_impl(x); }
double pow(double x, double y) { return _pow_impl(x, y); }

double sin(double x) { return _sin_impl(x); }
double cos(double x) { return _cos_impl(x); }
double tan(double x) { return _tan_impl(x); }
double asin(double x) { return _asin_impl(x); }
double acos(double x) { return _acos_impl(x); }
double atan(double x) { return _atan_impl(x); }
double atan2(double y, double x) { return _atan2_impl(y, x); }

double sinh(double x) { return _sinh_impl(x); }
double cosh(double x) { return _cosh_impl(x); }
double tanh(double x) { return _tanh_impl(x); }
double asinh(double x) { return _asinh_impl(x); }
double acosh(double x) { return _acosh_impl(x); }
double atanh(double x) { return _atanh_impl(x); }

// Single precision intrinsics

float truncf(float x) {
#if __has_builtin(__builtin_truncf)
    return __builtin_truncf(x);
#else
    return _trunc_impl(x);
#endif
}

float roundf(float x) {
#if __has_builtin(__builtin_roundf)
    return __builtin_roundf(x);
#else
    return _round_impl(x);
#endif
}

float floorf(float x) {
#if __has_builtin(__builtin_floorf)
    return __builtin_floorf(x);
#else
    return _floor_impl(x);
#endif
}

float ceilf(float x) {
#if __has_builtin(__builtin_ceilf)
    return __builtin_ceilf(x);
#else
    return _ceil_impl(x);
#endif
}

float sqrtf(float x) {
#if __has_builtin(__builtin_sqrtf)
    return __builtin_sqrtf(x);
#else
    return _sqrt_impl(x);
#endif
}

float fabsf(float x) {
#if __has_builtin(__builtin_fabsf)
    return __builtin_fabsf(x);
#else
    return x < 0 ? -x : x;
#endif
}

float fmodf(float x, float y) {
#if __has_builtin(__builtin_fmodf)
    return __builtin_fmodf(x, y);
#else
    return x - y * (int)(x / y);
#endif
}

float modff(float value, float* intpart) {
#if __has_builtin(__builtin_modff)
    return __builtin_modff(value, intpart);
#else
    *intpart = trunc(value);
    return value - *intpart;
#endif
}

float ldexpf(float x, int exp) {
#if __has_builtin(__builtin_ldexpf)
    return __builtin_ldexpf(x, exp);
#else
    return x * powf(2, exp);
#endif
}

// Single precision functions imported from javascript

float logf(float x) { return _log_impl(x); }
float log2f(float x) { return _log2_impl(x); }
float log10f(float x) { return _log10_impl(x); }
float expf(float x) { return _exp_impl(x); }
float powf(float x, float y) { return _pow_impl(x, y); }

float sinf(float x) { return _sin_impl(x); }
float cosf(float x) { return _cos_impl(x); }
float tanf(float x) { return _tan_impl(x); }
float asinf(float x) { return _asin_impl(x); }
float acosf(float x) { return _acos_impl(x); }
float atanf(float x) { return _atan_impl(x); }
float atan2f(float y, float x) { return _atan2_impl(y, x); }

float sinhf(float x) { return _sinh_impl(x); }
float coshf(float x) { return _cosh_impl(x); }
float tanhf(float x) { return _tanh_impl(x); }
float asinhf(float x) { return _asinh_impl(x); }
float acoshf(float x) { return _acosh_impl(x); }
float atanhf(float x) { return _atanh_impl(x); }

// Exceptions
int feclearexcept(int excepts) { return 0; }
int fetestexcept(int excepts) { return 0; }

// Random

void srand(unsigned seed) {}
int  rand() { return _random_impl() * RAND_MAX; }

// NaN

double nan(const char* tagp) {
#if __has_builtin(__builtin_nan)
    return __builtin_nan(tagp);
#else
    return 0.0 / 0.0;
#endif
}
float nanf(const char* tagp) {
#if __has_builtin(__builtin_nanf)
    return __builtin_nanf(tagp);
#else
    return 0.0f / 0.0f;
#endif
}
