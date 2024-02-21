#include <time.h>

size_t strftime(char* s, size_t max, const char* restrict format, const struct tm* restrict tm) {
    __builtin_trap();
}
