//===-- Implementation of fminf function ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/fminf.h"
#include "c/std/__support/FPUtil/BasicOperations.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, fminf, (float x, float y)) {
  return fputil::fmin(x, y);
}

} // namespace __llvm_libc
