//===-- Implementation of rindex ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/rindex.h"

#include "c/std/__support/common.h"
#include "c/std/string/string_utils.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, rindex, (const char *src, int c)) {
  return internal::strrchr_implementation(src, c);
}

} // namespace __llvm_libc
