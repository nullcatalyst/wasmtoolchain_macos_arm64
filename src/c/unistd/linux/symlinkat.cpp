//===-- Linux implementation of symlinkat ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/symlinkat.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include "src/c/errno/libc_errno.h"
#include <fcntl.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, symlinkat,
                   (const char *path1, int fd, const char *path2)) {
  // long ret = __llvm_libc::syscall_impl(SYS_symlinkat, path1, fd, path2);
  // if (ret < 0) {
  //   libc_errno = -ret;
  //   return -1;
  // }
  // return ret;
  __builtin_trap();
}

} // namespace __llvm_libc