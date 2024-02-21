//===-- Implementation of strncmp -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/strncmp.h"

#include "src/c/__support/common.h"
#include "src/c/string/memory_utils/inline_strcmp.h"

#include <stddef.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, strncmp,
                   (const char *left, const char *right, size_t n)) {
  auto comp = [](char l, char r) -> int { return l - r; };
  return inline_strncmp(left, right, n, comp);
}

} // namespace __llvm_libc
