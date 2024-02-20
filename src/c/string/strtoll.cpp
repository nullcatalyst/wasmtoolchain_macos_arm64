#include <cstdlib>

#include "src/c/string/strtointeger.hpp"

extern "C" long long strtoll(const char* __restrict str, char** __restrict str_end, int base) {
    auto result = internal::strtointeger<long long>(str, base);
    if (result.has_error()) errno = result.error;

    if (str_end != nullptr) *str_end = const_cast<char*>(str + result.parsed_len);

    return result;
}
