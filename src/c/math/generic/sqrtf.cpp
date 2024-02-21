//===-- Implementation of sqrtf function ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/sqrtf.h"
#include "src/c/__support/FPUtil/sqrt.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, sqrtf, (float x)) { return fputil::sqrt(x); }

} // namespace __llvm_libc