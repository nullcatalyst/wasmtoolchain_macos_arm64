//===-- Implementation of open --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/fcntl/open.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"
#include "c/std/errno/libc_errno.h"

#include <fcntl.h>
#include <stdarg.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, open, (const char *path, int flags, ...)) {
//   mode_t mode_flags = 0;
//   // O_TMPFILE is a multi-bit flag so we test all bits by checking for equality
//   // with O_TMPFILE
//   if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE) {
//     va_list varargs;
//     va_start(varargs, flags);
//     mode_flags = va_arg(varargs, mode_t);
//     va_end(varargs);
//   }

// #ifdef SYS_open
//   int fd = __llvm_libc::syscall_impl(SYS_open, path, flags, mode_flags);
// #else
//   int fd =
//       __llvm_libc::syscall_impl(SYS_openat, AT_FDCWD, path, flags, mode_flags);
// #endif
//   if (fd > 0)
//     return fd;

//   libc_errno = -fd;
//   return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
