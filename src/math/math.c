#include <math.h>

#include "src/wasm.h"

WASM_IMPORT("math", "round") double _round_impl(double);
WASM_IMPORT("math", "floor") double _floor_impl(double);
WASM_IMPORT("math", "ceil") double _ceil_impl(double);

WASM_IMPORT("math", "log") double _log_impl(double);
WASM_IMPORT("math", "log2") double _log2_impl(double);
WASM_IMPORT("math", "log10") double _log10_impl(double);
WASM_IMPORT("math", "exp") double _exp_impl(double);
WASM_IMPORT("math", "pow") double _pow_impl(double, double);
WASM_IMPORT("math", "sqrt") double _sqrt_impl(double);

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

// Double precision
double round(double x) { return _round_impl(x); }
double floor(double x) { return _floor_impl(x); }
double ceil(double x) { return _ceil_impl(x); }

double log(double x) { return _log_impl(x); }
double log2(double x) { return _log2_impl(x); }
double log10(double x) { return _log_impl(x); }
double exp(double x) { return _exp_impl(x); }
double pow(double x, double y) { return _pow_impl(x, y); }
double sqrt(double x) { return _sqrt_impl(x); }

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

// Single precision
float roundf(float x) { return _round_impl(x); }
float floorf(float x) { return _floor_impl(x); }
float ceilf(float x) { return _ceil_impl(x); }

float logf(float x) { return _log_impl(x); }
float log2f(float x) { return _log2_impl(x); }
float log10f(float x) { return _log10_impl(x); }
float expf(float x) { return _exp_impl(x); }
float powf(float x, float y) { return _pow_impl(x, y); }
float sqrtf(float x) { return _sqrt_impl(x); }

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
