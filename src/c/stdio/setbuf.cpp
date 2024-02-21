//===-- Implementation of setbuf ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/setbuf.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void, setbuf,
                   (::FILE *__restrict stream, char *__restrict buf)) {
  // int mode = _IOFBF;
  // if (buf == nullptr)
  //   mode = _IONBF;
  // int err = reinterpret_cast<__llvm_libc::File *>(stream)->set_buffer(
  //     buf, BUFSIZ, mode);
  // if (err != 0)
  //   libc_errno = err;
  __WASM_PANIC();
}

} // namespace __llvm_libc
