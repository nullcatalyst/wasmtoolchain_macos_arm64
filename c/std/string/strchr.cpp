//===-- Implementation of strchr ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strchr.h"

#include "c/std/__support/common.h"
#include "c/std/string/string_utils.h"

namespace __llvm_libc {

// TODO: Look at performance benefits of comparing words.
LLVM_LIBC_FUNCTION(char *, strchr, (const char *src, int c)) {
  return internal::strchr_implementation(src, c);
}

} // namespace __llvm_libc
