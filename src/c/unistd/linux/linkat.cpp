//===-- Linux implementation of linkat ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/linkat.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include "src/c/errno/libc_errno.h"
#include <fcntl.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, linkat,
                   (int fd1, const char *path1, int fd2, const char *path2,
                    int flags)) {
  // long ret =
  //     __llvm_libc::syscall_impl(SYS_linkat, fd1, path1, fd2, path2, flags);
  // if (ret < 0) {
  //   libc_errno = -ret;
  //   return -1;
  // }
  // return ret;
  __WASM_PANIC();
}

} // namespace __llvm_libc
