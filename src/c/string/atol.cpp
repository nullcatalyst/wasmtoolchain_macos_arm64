#include <cstdlib>

#include "src/c/string/strtointeger.hpp"

extern "C" long atol(const char* str) {
    auto result = internal::strtointeger<long>(str, 10);
    if (result.has_error()) errno = result.error;
    return result;
}
