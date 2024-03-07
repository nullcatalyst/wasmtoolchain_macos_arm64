//===-- Implementation of logbl function ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/logbl.h"
#include "c/std/__support/FPUtil/ManipulationFunctions.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long double, logbl, (long double x)) {
  return fputil::logb(x);
}

} // namespace __llvm_libc