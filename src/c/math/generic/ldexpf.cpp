//===-- Implementation of ldexpf function ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/ldexpf.h"
#include "src/c/__support/FPUtil/ManipulationFunctions.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, ldexpf, (float x, int exp)) {
  return fputil::ldexp(x, exp);
}

} // namespace __llvm_libc
