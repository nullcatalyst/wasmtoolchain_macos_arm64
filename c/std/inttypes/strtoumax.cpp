//===-- Implementation of strtoumax ---------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/inttypes/strtoumax.h"
#include "c/std/__support/common.h"
#include "c/std/__support/str_to_integer.h"
#include "c/std/errno/libc_errno.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(uintmax_t, strtoumax,
                   (const char *__restrict str, char **__restrict str_end,
                    int base)) {
  auto result = internal::strtointeger<uintmax_t>(str, base);
  if (result.has_error())
    libc_errno = result.error;

  if (str_end != nullptr)
    *str_end = const_cast<char *>(str + result.parsed_len);

  return result;
}

} // namespace __llvm_libc
