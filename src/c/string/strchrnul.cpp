//===-- Implementation of strchrnul --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/strchrnul.h"
#include "src/c/string/string_utils.h"

#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, strchrnul, (const char *src, int c)) {
  return internal::strchr_implementation<false>(src, c);
}

} // namespace __llvm_libc