//===-- Implementation of bzero -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/bzero.h"
#include "c/std/__support/common.h"
#include "c/std/string/memory_utils/inline_bzero.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, bzero, (void *ptr, size_t count)) {
  inline_bzero(reinterpret_cast<char *>(ptr), count);
}

} // namespace __llvm_libc
