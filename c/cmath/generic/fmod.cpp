//===-- Double-precision fmod function ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/fmod.h"
#include "c/std/__support/FPUtil/generic/FMod.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(double, fmod, (double x, double y)) {
  return fputil::generic::FMod<double>::eval(x, y);
}

} // namespace __llvm_libc
