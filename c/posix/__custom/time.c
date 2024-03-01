#include <stdint.h>
#include <time.h>

#include "c/wasm.h"

WASM_IMPORT("time", "now_unix") uint64_t __time_now_unix();

time_t time(time_t* _Nullable tloc) {
    time_t now = __time_now_unix() / 1000;
    if (tloc) {
        *tloc = now;
    }
    return now;
}
