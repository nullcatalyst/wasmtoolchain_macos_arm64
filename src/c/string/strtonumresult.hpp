#pragma once

#include <cstddef>

namespace internal {

template <typename T>
struct StrToNumResult {
    T         value;
    int       error;
    ptrdiff_t parsed_len;

    inline constexpr StrToNumResult(T value) : value(value), error(0), parsed_len(0) {}
    inline constexpr StrToNumResult(T value, ptrdiff_t parsed_len)
        : value(value), error(0), parsed_len(parsed_len) {}
    inline constexpr StrToNumResult(T value, ptrdiff_t parsed_len, int error)
        : value(value), error(error), parsed_len(parsed_len) {}

    inline constexpr bool has_error() { return error != 0; }

    inline constexpr operator T() { return value; }
};

}  // namespace internal
