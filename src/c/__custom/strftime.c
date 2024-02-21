#include <time.h>

#include "src/c/__custom/panic.h"

size_t strftime(char* s, size_t max, const char* restrict format, const struct tm* restrict tm) {
    __WASM_PANIC();
}
