//===-- Implementation of strcasestr --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/strcasestr.h"

#include "src/c/__support/common.h"
#include "src/c/__support/ctype_utils.h"
#include "src/c/string/memory_utils/inline_strstr.h"

namespace __llvm_libc {

// TODO: This is a simple brute force implementation. This can be
// improved upon using well known string matching algorithms.
LLVM_LIBC_FUNCTION(char *, strcasestr,
                   (const char *haystack, const char *needle)) {
  auto case_cmp = [](char a, char b) {
    return __llvm_libc::internal::tolower(a) -
           __llvm_libc::internal::tolower(b);
  };
  return inline_strstr(haystack, needle, case_cmp);
}

} // namespace __llvm_libc