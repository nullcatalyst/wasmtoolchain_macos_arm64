//===-- Implementation of truncf function ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/math/truncf.h"
#include "src/c/__support/FPUtil/NearestIntegerOperations.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(float, truncf, (float x)) { return fputil::trunc(x); }

} // namespace __llvm_libc