#include <cerrno>
#include <cstdlib>

#include "src/c/string/strtofloat.hpp"

extern "C" double strtod(const char* __restrict str, char** __restrict str_end) {
    auto result = internal::strtofloatingpoint<double>(str);
    if (result.has_error()) errno = result.error;

    if (str_end != NULL) *str_end = const_cast<char*>(str + result.parsed_len);

    return result.value;
}
