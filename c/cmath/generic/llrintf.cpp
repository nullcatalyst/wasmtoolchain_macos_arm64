//===-- Implementation of llrintf function --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/cmath/llrintf.h"
#include "c/std/__support/FPUtil/NearestIntegerOperations.h"
#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long long, llrintf, (float x)) {
  return fputil::round_to_signed_integer_using_current_rounding_mode<float,
                                                                     long long>(
      x);
}

} // namespace __llvm_libc
