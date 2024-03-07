//===-- Implementation of modf function -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/modff.h"
#include "c/std/__support/FPUtil/ManipulationFunctions.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, modff, (float x, float *iptr)) {
  return fputil::modf(x, *iptr);
}

} // namespace __llvm_libc