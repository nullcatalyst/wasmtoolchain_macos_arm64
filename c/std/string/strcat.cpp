//===-- Implementation of strcat ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strcat.h"
#include "c/std/string/strcpy.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, strcat,
                   (char *__restrict dest, const char *__restrict src)) {
  size_t dest_length = internal::string_length(dest);
  size_t src_length = internal::string_length(src);
  __llvm_libc::strcpy(dest + dest_length, src);
  dest[dest_length + src_length] = '\0';
  return dest;
}

} // namespace __llvm_libc
