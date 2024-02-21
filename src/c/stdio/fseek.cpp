//===-- Implementation of fseek -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/fseek.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, fseek, (::FILE * stream, long offset, int whence)) {
  // auto result =
  //     reinterpret_cast<__llvm_libc::File *>(stream)->seek(offset, whence);
  // if (!result.has_value()) {
  //   libc_errno = result.error();
  //   return -1;
  // }
  // return 0;
  __builtin_trap();
}

} // namespace __llvm_libc
