//===-- Implementation of strxfrm -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strxfrm.h"
#include "c/std/string/memory_utils/inline_memcpy.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

// TODO: Add support for locales.
LLVM_LIBC_FUNCTION(size_t, strxfrm,
                   (char *__restrict dest, const char *__restrict src,
                    size_t n)) {
  size_t len = internal::string_length(src);
  if (n > len)
    inline_memcpy(dest, src, len + 1);
  return len;
}

} // namespace __llvm_libc