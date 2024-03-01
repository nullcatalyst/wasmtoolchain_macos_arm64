//===-- Linux implementation of sigprocmask -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/signal/sigprocmask.h"
#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/errno/libc_errno.h"
#include "c/posix/signal/linux/signal_utils.h"

#include "c/std/__support/common.h"

#include <signal.h>
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, sigprocmask,
                   (int how, const sigset_t *__restrict set,
                    sigset_t *__restrict oldset)) {
  // int ret = __llvm_libc::syscall_impl(SYS_rt_sigprocmask, how, set, oldset,
  //                                     sizeof(sigset_t));
  // if (!ret)
  //   return 0;

  // libc_errno = -ret;
  // return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
