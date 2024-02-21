//===-- Implementation of creat -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/fcntl/creat.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"
#include "src/c/errno/libc_errno.h"

#include <fcntl.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, creat, (const char *path, int mode_flags)) {
// #ifdef SYS_open
//   int fd = __llvm_libc::syscall_impl(SYS_open, path,
//                                      O_CREAT | O_WRONLY | O_TRUNC, mode_flags);
// #else
//   int fd = __llvm_libc::syscall_impl(SYS_openat, AT_FDCWD, path,
//                                      O_CREAT | O_WRONLY | O_TRUNC, mode_flags);
// #endif

//   if (fd > 0)
//     return fd;

//   libc_errno = -fd;
//   return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
