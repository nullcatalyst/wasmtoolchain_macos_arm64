//===-- Linux implementation of lstat -------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/sys/stat/lstat.h"
#include "kernel_statx.h"
#include "src/c/errno/libc_errno.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include <fcntl.h>
#include <sys/stat.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, lstat,
                   (const char *__restrict path,
                    struct stat *__restrict statbuf)) {
  // int err = statx(AT_FDCWD, path, AT_SYMLINK_NOFOLLOW, statbuf);
  // if (err != 0) {
  //   libc_errno = err;
  //   return -1;
  // }
  // return 0;
  return 0;
}

} // namespace __llvm_libc
