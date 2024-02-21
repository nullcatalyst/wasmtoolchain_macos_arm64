#include <time.h>

struct tm* localtime(const time_t* timer) { __builtin_trap(); }

struct tm* localtime_r(const time_t* restrict timer, struct tm* restrict result) {
    __builtin_trap();
}
