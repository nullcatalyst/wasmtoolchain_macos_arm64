//===-- Linux implementation of getuid ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/unistd/getuid.h"

#include "src/c/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/c/__support/common.h"

#include <sys/syscall.h> // For syscall numbers.

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(uid_t, getuid, ()) {
  // return __llvm_libc::syscall_impl(SYS_getuid);
  __builtin_trap();
}

} // namespace __llvm_libc