//===-- Implementation of openat ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/fcntl/openat.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"
#include "src/c/errno/libc_errno.h"

#include <fcntl.h>
#include <stdarg.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, openat, (int dfd, const char *path, int flags, ...)) {
  // mode_t mode_flags = 0;
  // // O_TMPFILE is a multi-bit flag so we test all bits by checking for equality
  // // with O_TMPFILE
  // if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE) {
  //   va_list varargs;
  //   va_start(varargs, flags);
  //   mode_flags = va_arg(varargs, mode_t);
  //   va_end(varargs);
  // }

  // int fd = __llvm_libc::syscall_impl(SYS_openat, dfd, path, flags, mode_flags);
  // if (fd > 0)
  //   return fd;

  // libc_errno = -fd;
  // return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
