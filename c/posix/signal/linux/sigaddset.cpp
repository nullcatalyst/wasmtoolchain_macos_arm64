//===-- Linux implementation of sigaddset ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/signal/sigaddset.h"
#include "c/std/__support/common.h"
#include "c/std/errno/libc_errno.h"
#include "c/posix/signal/linux/signal_utils.h"

#include <signal.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, sigaddset, (sigset_t * set, int signum)) {
  // if (set != nullptr && add_signal(*set, signum))
  //   return 0;
  // libc_errno = EINVAL;
  // return -1;
  __WASM_PANIC();
}

} // namespace __llvm_libc
