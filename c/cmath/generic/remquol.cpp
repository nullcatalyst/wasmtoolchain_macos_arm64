//===-- Implementation of remquol function --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/remquol.h"
#include "c/std/__support/FPUtil/DivisionAndRemainderOperations.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long double, remquol,
                   (long double x, long double y, int *exp)) {
  return fputil::remquo(x, y, *exp);
}

} // namespace __llvm_libc
