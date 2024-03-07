//===-- Implementation of fmaf function -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/fmaf.h"
#include "c/std/__support/common.h"

#include "c/std/__support/FPUtil/FMA.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, fmaf, (float x, float y, float z)) {
  return fputil::fma(x, y, z);
}

} // namespace __llvm_libc