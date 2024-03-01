//===-- Linux implementation of uname -------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/sys/utsname/uname.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"

#include "c/std/errno/libc_errno.h"
#include <sys/syscall.h> // For syscall numbers.
#include <sys/utsname.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, uname, (struct utsname * name)) {
  // long ret = __llvm_libc::syscall_impl(SYS_uname, name);

  // if (ret >= 0)
  //   return 1;
  // libc_errno = -ret;
  // return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
