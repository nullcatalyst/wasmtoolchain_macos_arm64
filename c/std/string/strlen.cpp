//===-- Implementation of strlen ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/string/strlen.h"
#include "c/std/string/string_utils.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

// TODO: investigate the performance of this function.
// There might be potential for compiler optimization.
LLVM_LIBC_FUNCTION(size_t, strlen, (const char *src)) {
  return internal::string_length(src);
}

} // namespace __llvm_libc
