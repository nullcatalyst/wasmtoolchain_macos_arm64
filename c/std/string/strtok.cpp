//===-- Implementation of strtok ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strtok.h"

#include "c/std/__support/common.h"
#include "c/std/string/string_utils.h"

namespace __llvm_libc {

static char *strtok_str = nullptr;

LLVM_LIBC_FUNCTION(char *, strtok,
                   (char *__restrict src,
                    const char *__restrict delimiter_string)) {
  return internal::string_token(src, delimiter_string, &strtok_str);
}

} // namespace __llvm_libc
