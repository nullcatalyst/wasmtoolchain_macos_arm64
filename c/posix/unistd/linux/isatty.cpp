//===-- Linux implementation of isatty ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/unistd/isatty.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"

#include "c/std/errno/libc_errno.h"
#include <sys/ioctl.h>   // For ioctl numbers.
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, isatty, (int fd)) {
  // constexpr int INIT_VAL = 0x1234abcd;
  // int line_d_val = INIT_VAL;
  // // This gets the line dicipline of the terminal. When called on something that
  // // isn't a terminal it doesn't change line_d_val and returns -1.
  // int result = __llvm_libc::syscall_impl(SYS_ioctl, fd, TIOCGETD, &line_d_val);
  // if (result == 0)
  //   return 1;

  // libc_errno = -result;
  // return 0;
  __WASM_PANIC();
}

} // namespace __llvm_libc