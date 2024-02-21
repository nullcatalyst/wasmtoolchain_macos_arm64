//===-- Linux implementation of signal ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/signal/signal.h"
#include "src/c/signal/sigaction.h"

#include "src/c/__support/common.h"

#include <signal.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(sighandler_t, signal, (int signum, sighandler_t handler)) {
  // struct sigaction action, old;
  // action.sa_handler = handler;
  // action.sa_flags = SA_RESTART;
  // // Errno will already be set so no need to worry about changing errno here.
  // return __llvm_libc::sigaction(signum, &action, &old) == -1 ? SIG_ERR
  //                                                            : old.sa_handler;
  __builtin_trap();
}

} // namespace __llvm_libc
