//===-- Implementation of bcopy -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/bcopy.h"
#include "c/std/__support/common.h"
#include "c/std/string/memory_utils/inline_memmove.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, bcopy, (const void *src, void *dst, size_t count)) {
  return inline_memmove(dst, src, count);
}

} // namespace __llvm_libc
