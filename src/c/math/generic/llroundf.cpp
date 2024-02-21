//===-- Implementation of llroundf function -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/llroundf.h"
#include "src/c/__support/FPUtil/NearestIntegerOperations.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long long, llroundf, (float x)) {
  return fputil::round_to_signed_integer<float, long long>(x);
}

} // namespace __llvm_libc