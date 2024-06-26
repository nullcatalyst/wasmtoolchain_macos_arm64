//===-- Linux implementation of socket ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/posix/sys/socket/socket.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"

#include "c/std/errno/libc_errno.h"

// #include <linux/net.h>   // For SYS_SOCKET socketcall number.
#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, socket, (int domain, int type, int protocol)) {
// #ifdef SYS_socket
//   long ret = __llvm_libc::syscall_impl(SYS_socket, domain, type, protocol);
// #elif defined(SYS_socketcall)
//   unsigned long sockcall_args[3] = {domain, type, protocol};
//   long ret =
//       __llvm_libc::syscall_impl(SYS_socketcall, SYS_SOCKET, sockcall_args);
// #else
// #error "socket and socketcall syscalls unavailable for this platform."
// #endif
//   if (ret < 0) {
//     libc_errno = -ret;
//     return -1;
//   }
//   return ret;
  __WASM_PANIC();
}

} // namespace __llvm_libc
