//===-- Implementation of memmem ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/memmem.h"
#include "src/c/__support/common.h"
#include "src/c/string/memory_utils/inline_memmem.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void *, memmem,
                   (const void *haystack, size_t haystack_len,
                    const void *needle, size_t needle_len)) {
  constexpr auto comp = [](unsigned char l, unsigned char r) -> int {
    return l - r;
  };
  return inline_memmem(haystack, haystack_len, needle, needle_len, comp);
}

} // namespace __llvm_libc