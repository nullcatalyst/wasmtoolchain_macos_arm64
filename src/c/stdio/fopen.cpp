//===-- Implementation of fopen -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/fopen.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(::FILE *, fopen,
                   (const char *__restrict name, const char *__restrict mode)) {
  // auto result = __llvm_libc::openfile(name, mode);
  // if (!result.has_value()) {
  //   libc_errno = result.error();
  //   return nullptr;
  // }
  // return reinterpret_cast<::FILE *>(result.value());
  __WASM_PANIC();
}

} // namespace __llvm_libc
