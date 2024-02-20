#pragma once

#include <cstdlib>

namespace internal {

// Create a bitmask with the count right-most bits set to 1, and all other bits
// set to 0.  Only unsigned types are allowed.
template <typename T, size_t count>
inline constexpr T mask_trailing_ones() {
    static_assert(std::is_unsigned_v<T>);
    constexpr unsigned t_bits = CHAR_BIT * sizeof(T);
    static_assert(count <= t_bits && "Invalid bit index");
    // It's important not to initialize T with -1, since T may be BigInt which
    // will take -1 as a uint64_t and only initialize the low 64 bits.
    constexpr T all_zeroes(0);
    constexpr T all_ones(~all_zeroes);  // bitwise NOT performs integer promotion.
    return count == 0 ? 0 : (all_ones >> (t_bits - count));
}

// Create a bitmask with the count left-most bits set to 1, and all other bits
// set to 0.  Only unsigned types are allowed.
template <typename T, size_t count>
inline constexpr T mask_leading_ones() {
    constexpr T mask(mask_trailing_ones<T, CHAR_BIT * sizeof(T) - count>());
    return T(~mask);  // bitwise NOT performs integer promotion.
}

}  // namespace internal
