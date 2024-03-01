//===-- Implementation of strcpy ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strcpy.h"
#include "c/std/string/memory_utils/inline_memcpy.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, strcpy,
                   (char *__restrict dest, const char *__restrict src)) {
  size_t size = internal::string_length(src) + 1;
  inline_memcpy(dest, src, size);
  return dest;
}

} // namespace __llvm_libc
