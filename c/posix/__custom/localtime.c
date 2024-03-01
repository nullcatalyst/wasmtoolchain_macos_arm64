#include <time.h>

#include "c/wasm.h"

struct tm* localtime(const time_t* timer) { __WASM_PANIC(); }

struct tm* localtime_r(const time_t* restrict timer, struct tm* restrict result) { __WASM_PANIC(); }
