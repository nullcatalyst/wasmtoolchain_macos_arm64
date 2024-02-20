#include <stdint.h>
#include <time.h>

#include "src/wasm.h"

WASM_IMPORT("time", "now") uint64_t _time_now();

time_t time(time_t* _Nullable tloc) {
    time_t now = _time_now() / 1000;
    if (tloc) {
        *tloc = now;
    }
    return now;
}

localtime_r