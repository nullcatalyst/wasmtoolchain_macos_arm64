#include <time.h>

#include "src/c/__custom/panic.h"

struct tm* localtime(const time_t* timer) { __WASM_PANIC(); }

struct tm* localtime_r(const time_t* restrict timer, struct tm* restrict result) {
    __WASM_PANIC();
}
