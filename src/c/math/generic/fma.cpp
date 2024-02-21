//===-- Implementation of fma function ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/fma.h"
#include "src/c/__support/common.h"

#include "src/c/__support/FPUtil/FMA.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(double, fma, (double x, double y, double z)) {
  return fputil::fma(x, y, z);
}

} // namespace __llvm_libc