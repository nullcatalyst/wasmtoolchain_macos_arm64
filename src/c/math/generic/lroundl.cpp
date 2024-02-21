//===-- Implementation of lroundl function --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/lroundl.h"
#include "src/c/__support/FPUtil/NearestIntegerOperations.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long, lroundl, (long double x)) {
  return fputil::round_to_signed_integer<long double, long>(x);
}

} // namespace __llvm_libc