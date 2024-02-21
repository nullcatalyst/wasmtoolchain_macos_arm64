//===-- Implementation of fmax function -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/fmax.h"
#include "src/c/__support/FPUtil/BasicOperations.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(double, fmax, (double x, double y)) {
  return fputil::fmax(x, y);
}

} // namespace __llvm_libc