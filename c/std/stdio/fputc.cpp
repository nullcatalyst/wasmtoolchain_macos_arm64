//===-- Implementation of fputc -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/fputc.h"
// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION

#include "c/std/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, fputc, (int c, ::FILE *stream)) {
  // unsigned char uc = static_cast<unsigned char>(c);

  // auto result = reinterpret_cast<__llvm_libc::File *>(stream)->write(&uc, 1);
  // if (result.has_error())
  //   libc_errno = result.error;
  // size_t written = result.value;

  // if (1 != written) {
  //   // The stream should be in an error state in this case.
  //   return EOF;
  // }
  // return 0;
  __WASM_PANIC();
}

} // namespace __llvm_libc
