//===-- Implementation of strpbrk -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strpbrk.h"

#include "c/std/__support/common.h"
#include "c/std/string/string_utils.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, strpbrk, (const char *src, const char *breakset)) {
  src += internal::complementary_span(src, breakset);
  return *src ? const_cast<char *>(src) : nullptr;
}

} // namespace __llvm_libc
