//===-- Linux implementation of fchdir ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/unistd/fchdir.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"

#include "c/std/errno/libc_errno.h"
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, fchdir, (int fd)) {
  // long ret = __llvm_libc::syscall_impl(SYS_fchdir, fd);
  // if (ret < 0) {
  //   libc_errno = -ret;
  //   return -1;
  // }
  // return 0;
  __WASM_PANIC();
}

} // namespace __llvm_libc
