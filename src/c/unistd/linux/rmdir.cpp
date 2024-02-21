//===-- Linux implementation of rmdir -------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/rmdir.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"
#include "src/c/errno/libc_errno.h"

#include <fcntl.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, rmdir, (const char *path)) {
// #ifdef SYS_rmdir
//   long ret = __llvm_libc::syscall_impl(SYS_rmdir, path);
// #elif defined(SYS_unlinkat)
//   long ret =
//       __llvm_libc::syscall_impl(SYS_unlinkat, AT_FDCWD, path, AT_REMOVEDIR);
// #else
// #error "rmdir and unlinkat syscalls not available."
// #endif

//   if (ret < 0) {
//     libc_errno = -ret;
//     return -1;
//   }
//   return 0;
  __WASM_PANIC();
}

} // namespace __llvm_libc
