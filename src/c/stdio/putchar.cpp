//===-- Implementation of putchar -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/putchar.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, putchar, (int c)) {
  // unsigned char uc = static_cast<unsigned char>(c);

  // auto result = __llvm_libc::stdout->write(&uc, 1);
  // if (result.has_error())
  //   libc_errno = result.error;
  // size_t written = result.value;

  // if (1 != written) {
  //   // The stream should be in an error state in this case.
  //   return EOF;
  // }
  // return 0;
  __builtin_trap();
}

} // namespace __llvm_libc