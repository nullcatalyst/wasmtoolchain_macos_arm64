//===-- Implementation of llabs -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdlib/llabs.h"
#include "src/c/__support/common.h"
#include "src/c/__support/integer_operations.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long long, llabs, (long long n)) { return integer_abs(n); }

} // namespace __llvm_libc
