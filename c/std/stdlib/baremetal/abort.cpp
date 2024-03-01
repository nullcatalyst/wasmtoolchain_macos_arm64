//===-- Implementation of abort -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/__support/common.h"

#include "c/std/stdlib/abort.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, abort, ()) { __WASM_PANIC(); }

} // namespace __llvm_libc
