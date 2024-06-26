//===-- Implementation of strcasecmp --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strcasecmp.h"

#include "c/std/__support/common.h"
#include "c/std/__support/ctype_utils.h"
#include "c/std/string/memory_utils/inline_strcmp.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, strcasecmp, (const char *left, const char *right)) {
  auto case_cmp = [](char a, char b) {
    return __llvm_libc::internal::tolower(a) -
           __llvm_libc::internal::tolower(b);
  };
  return inline_strcmp(left, right, case_cmp);
}

} // namespace __llvm_libc
