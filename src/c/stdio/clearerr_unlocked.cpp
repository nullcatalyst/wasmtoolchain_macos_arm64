//===-- Implementation of clearerr_unlocked -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/clearerr_unlocked.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, clearerr_unlocked, (::FILE * stream)) {
  // reinterpret_cast<__llvm_libc::File *>(stream)->clearerr_unlocked();
  __builtin_trap();
}

} // namespace __llvm_libc
