//===-- Implementation of sqrtl function ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/sqrtl.h"
#include "src/c/__support/FPUtil/sqrt.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long double, sqrtl, (long double x)) {
  return fputil::sqrt(x);
}

} // namespace __llvm_libc