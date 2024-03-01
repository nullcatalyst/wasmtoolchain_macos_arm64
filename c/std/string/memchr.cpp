//===-- Implementation of memchr ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/memchr.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"
#include <stddef.h>

namespace __llvm_libc {

// TODO: Look at performance benefits of comparing words.
LLVM_LIBC_FUNCTION(void *, memchr, (const void *src, int c, size_t n)) {
  return internal::find_first_character(
      reinterpret_cast<const unsigned char *>(src),
      static_cast<unsigned char>(c), n);
}

} // namespace __llvm_libc
