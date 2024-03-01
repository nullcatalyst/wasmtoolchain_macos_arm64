//===-- Implementation of wctob -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/wchar/wctob.h"
#include "c/std/__support/common.h"
#include "c/std/__support/wctype_utils.h"

#include <stdio.h> // for EOF.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, wctob, (wint_t c)) {
  auto result = internal::wctob(c);
  if (result.has_value()) {
    return result.value();
  } else {
    return EOF;
  }
}

} // namespace __llvm_libc
