//===-- Implementation of atol --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdlib/atol.h"
#include "src/c/__support/common.h"
#include "src/c/__support/str_to_integer.h"
#include "src/c/errno/libc_errno.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long, atol, (const char *str)) {
  auto result = internal::strtointeger<long>(str, 10);
  if (result.has_error())
    libc_errno = result.error;

  return result;
}

} // namespace __llvm_libc
