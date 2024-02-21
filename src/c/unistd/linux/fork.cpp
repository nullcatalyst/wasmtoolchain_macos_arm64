//===-- Linux implementation of fork --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/fork.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"
// #include "src/c/__support/threads/fork_callbacks.h"
// #include "src/c/__support/threads/thread.h" // For thread self object

#include "src/c/errno/libc_errno.h"
#include <signal.h>      // For SIGCHLD
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

// The implementation of fork here is very minimal. We will add more
// functionality and standard compliance in future.

LLVM_LIBC_FUNCTION(pid_t, fork, (void)) {
//   invoke_prepare_callbacks();
// #ifdef SYS_fork
//   pid_t ret = __llvm_libc::syscall_impl(SYS_fork);
// #elif defined(SYS_clone)
//   pid_t ret = __llvm_libc::syscall_impl(SYS_clone, SIGCHLD, 0);
// #else
// #error "fork and clone syscalls not available."
// #endif
//   if (ret == 0) {
//     // Return value is 0 in the child process.
//     // The child is created with a single thread whose self object will be a
//     // copy of parent process' thread which called fork. So, we have to fix up
//     // the child process' self object with the new process' tid.
//     self.attrib->tid = __llvm_libc::syscall_impl(SYS_gettid);
//     invoke_child_callbacks();
//     return 0;
//   }

//   if (ret < 0) {
//     // Error case, a child process was not created.
//     libc_errno = -ret;
//     return -1;
//   }

//   invoke_parent_callbacks();
//   return ret;
  __WASM_PANIC();
}

} // namespace __llvm_libc
