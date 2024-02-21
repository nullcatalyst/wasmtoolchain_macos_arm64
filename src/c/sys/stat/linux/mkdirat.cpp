//===-- Linux implementation of mkdirat -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/sys/stat/mkdirat.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include "src/c/errno/libc_errno.h"
#include <sys/stat.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, mkdirat, (int dfd, const char *path, mode_t mode)) {
// #ifdef SYS_mkdirat
//   long ret = __llvm_libc::syscall_impl(SYS_mkdirat, dfd, path, mode);
// #else
// #error "mkdirat syscall not available."
// #endif

//   if (ret < 0) {
//     libc_errno = -ret;
//     return -1;
//   }
//   return 0;
  return 0;
}

} // namespace __llvm_libc