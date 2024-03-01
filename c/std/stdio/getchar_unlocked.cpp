//===-- Implementation of getchar_unlocked --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/getchar_unlocked.h"
// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION

#include "c/std/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, getchar_unlocked, ()) {
  // unsigned char c;
  // auto result = stdin->read_unlocked(&c, 1);
  // if (result.has_error())
  //   libc_errno = result.error;

  // if (result.value != 1)
  //   return EOF;
  // return c;
  __WASM_PANIC();
}

} // namespace __llvm_libc
