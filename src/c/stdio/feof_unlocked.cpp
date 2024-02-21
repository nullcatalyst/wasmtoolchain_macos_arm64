//===-- Implementation of feof_unlocked -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/feof_unlocked.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, feof_unlocked, (::FILE * stream)) {
  // return reinterpret_cast<__llvm_libc::File *>(stream)->iseof_unlocked();
  __builtin_trap();
}

} // namespace __llvm_libc
