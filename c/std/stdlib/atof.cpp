//===-- Implementation of atof --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdlib/atof.h"
#include "c/std/__support/common.h"
#include "c/std/__support/str_to_float.h"
#include "c/std/errno/libc_errno.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(double, atof, (const char *str)) {
  auto result = internal::strtofloatingpoint<double>(str);
  if (result.has_error())
    libc_errno = result.error;

  return result.value;
}

} // namespace __llvm_libc
