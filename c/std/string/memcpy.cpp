//===-- Implementation of memcpy ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/memcpy.h"
#include "c/std/__support/common.h"
#include "c/std/string/memory_utils/inline_memcpy.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(void *, memcpy,
                   (void *__restrict dst, const void *__restrict src,
                    size_t size)) {
  inline_memcpy(dst, src, size);
  return dst;
}

} // namespace __llvm_libc
