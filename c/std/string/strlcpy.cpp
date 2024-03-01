//===-- Implementation of strlcpy -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strlcpy.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(size_t, strlcpy,
                   (char *__restrict dst, const char *__restrict src,
                    size_t size)) {
  return internal::strlcpy(dst, src, size);
}

} // namespace __llvm_libc
