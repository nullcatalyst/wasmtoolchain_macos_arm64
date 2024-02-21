//===-- Implementation of abort -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/__support/common.h"

#include "src/c/stdlib/abort.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, abort, ()) { __builtin_trap(); }

} // namespace __llvm_libc