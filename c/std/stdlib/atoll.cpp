//===-- Implementation of atoll -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdlib/atoll.h"
#include "c/std/__support/common.h"
#include "c/std/__support/str_to_integer.h"
#include "c/std/errno/libc_errno.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long long, atoll, (const char *str)) {
  auto result = internal::strtointeger<long long>(str, 10);
  if (result.has_error())
    libc_errno = result.error;

  return result;
}

} // namespace __llvm_libc
