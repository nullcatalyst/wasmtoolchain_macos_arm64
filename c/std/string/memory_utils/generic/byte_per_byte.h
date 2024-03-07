//===-- Trivial byte per byte implementations  ----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// Straightforward implementations targeting the smallest code size possible.
// This needs to be compiled with '-Os' or '-Oz'.
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_STRING_MEMORY_UTILS_GENERIC_BYTE_PER_BYTE_H
#define LLVM_LIBC_SRC_STRING_MEMORY_UTILS_GENERIC_BYTE_PER_BYTE_H

#include "c/std/__support/macros/config.h"       // LIBC_INLINE
#include "c/std/__support/macros/optimization.h" // LIBC_LOOP_NOUNROLL
#include "c/std/string/memory_utils/utils.h"     // Ptr, CPtr

#include <stddef.h> // size_t

namespace __llvm_libc {

[[maybe_unused]] __attribute__((no_builtin("memcpy"))) LIBC_INLINE void
inline_memcpy_byte_per_byte(Ptr dst, CPtr src, size_t count,
                            size_t offset = 0) {
  LIBC_LOOP_NOUNROLL
  for (; offset < count; ++offset)
    dst[offset] = src[offset];
}

[[maybe_unused]] __attribute__((no_builtin("memmove"))) LIBC_INLINE void
inline_memmove_byte_per_byte(Ptr dst, CPtr src, size_t count) {
  if (count == 0 || dst == src)
    return;
  if (dst < src) {
    LIBC_LOOP_NOUNROLL
    for (size_t offset = 0; offset < count; ++offset)
      dst[offset] = src[offset];
  } else {
    LIBC_LOOP_NOUNROLL
    for (ptrdiff_t offset = count - 1; offset >= 0; --offset)
      dst[offset] = src[offset];
  }
}

[[maybe_unused]] __attribute__((no_builtin("memset"))) LIBC_INLINE static void
inline_memset_byte_per_byte(Ptr dst, uint8_t value, size_t count,
                            size_t offset = 0) {
  LIBC_LOOP_NOUNROLL
  for (; offset < count; ++offset)
    dst[offset] = static_cast<cpp::byte>(value);
}

[[maybe_unused]] __attribute__((no_builtin("bcmp"))) LIBC_INLINE BcmpReturnType
inline_bcmp_byte_per_byte(CPtr p1, CPtr p2, size_t count, size_t offset = 0) {
  LIBC_LOOP_NOUNROLL
  for (; offset < count; ++offset)
    if (p1[offset] != p2[offset])
      return BcmpReturnType::NONZERO();
  return BcmpReturnType::ZERO();
}

[[maybe_unused]] __attribute__((no_builtin("memcmp"))) LIBC_INLINE MemcmpReturnType
inline_memcmp_byte_per_byte(CPtr p1, CPtr p2, size_t count, size_t offset = 0) {
  LIBC_LOOP_NOUNROLL
  for (; offset < count; ++offset) {
    const int32_t a = static_cast<int32_t>(p1[offset]);
    const int32_t b = static_cast<int32_t>(p2[offset]);
    const int32_t diff = a - b;
    if (diff)
      return diff;
  }
  return MemcmpReturnType::ZERO();
}

} // namespace __llvm_libc

#endif // LLVM_LIBC_SRC_STRING_MEMORY_UTILS_GENERIC_BYTE_PER_BYTE_H