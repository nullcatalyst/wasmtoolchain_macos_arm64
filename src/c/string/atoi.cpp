#include <cstdlib>

#include "src/c/string/strtointeger.hpp"

extern "C" int atoi(const char* str) {
    auto result = internal::strtointeger<int>(str, 10);
    if (result.has_error()) errno = result.error;
    return result;
}
