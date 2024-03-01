//===-- Linux implementation of kill --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/signal/kill.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"
#include "c/std/errno/libc_errno.h"
#include "c/posix/signal/linux/signal_utils.h"

#include <signal.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, kill, (pid_t pid, int sig)) {
  // int ret = __llvm_libc::syscall_impl(SYS_kill, pid, sig);

  // // A negative return value indicates an error with the magnitude of the
  // // value being the error code.
  // if (ret != 0) {
  //   libc_errno = (ret > 0 ? ret : -ret);
  //   return -1;
  // }

  // return ret; // always 0
  __WASM_PANIC();
}

} // namespace __llvm_libc
