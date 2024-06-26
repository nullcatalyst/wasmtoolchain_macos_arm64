//===-- Single-precision scalbnl function ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/scalbnl.h"
#include "c/std/__support/FPUtil/ManipulationFunctions.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long double, scalbnl, (long double x, int n)) {
#if !defined(__FLT_RADIX__)
#error __FLT_RADIX__ undefined.
#elif __FLT_RADIX__ != 2
#error __FLT_RADIX__!=2, unimplemented.
#else
  return fputil::ldexp(x, n);
#endif
}

} // namespace __llvm_libc
