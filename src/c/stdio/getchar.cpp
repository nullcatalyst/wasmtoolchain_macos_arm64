//===-- Implementation of getchar -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/getchar.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, getchar, ()) {
  // unsigned char c;
  // auto result = stdin->read(&c, 1);
  // if (result.has_error())
  //   libc_errno = result.error;

  // if (result.value != 1)
  //   return EOF;
  // return c;
  __builtin_trap();
}

} // namespace __llvm_libc
