//===-- Implementation of ldiv --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdlib/ldiv.h"
#include "c/std/__support/common.h"
#include "c/std/__support/integer_operations.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(ldiv_t, ldiv, (long x, long y)) {
  ldiv_t res;
  integer_rem_quo(x, y, res.quot, res.rem);
  return res;
}

} // namespace __llvm_libc
