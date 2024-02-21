//===-- Linux implementation of access ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/access.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include "src/c/errno/libc_errno.h"
#include <fcntl.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, access, (const char *path, int mode)) {
// #ifdef SYS_access
//   long ret = __llvm_libc::syscall_impl(SYS_access, path, mode);
// #elif defined(SYS_faccessat)
//   long ret = __llvm_libc::syscall_impl(SYS_faccessat, AT_FDCWD, path, mode, 0);
// #else
// #error "access and faccessat syscalls not available."
// #endif

//   if (ret < 0) {
//     libc_errno = -ret;
//     return -1;
//   }
//   return 0;
  __builtin_trap();
}

} // namespace __llvm_libc