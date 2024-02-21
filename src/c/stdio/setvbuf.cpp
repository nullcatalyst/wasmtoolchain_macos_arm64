//===-- Implementation of setvbuf -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/setvbuf.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, setvbuf,
                   (::FILE *__restrict stream, char *__restrict buf, int type,
                    size_t size)) {
  // int err = reinterpret_cast<__llvm_libc::File *>(stream)->set_buffer(buf, size,
  //                                                                     type);
  // if (err != 0)
  //   libc_errno = err;
  // return err;
  __builtin_trap();
}

} // namespace __llvm_libc
