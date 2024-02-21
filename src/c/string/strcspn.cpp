//===-- Implementation of strcspn -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/strcspn.h"

#include "src/c/__support/common.h"
#include "src/c/string/string_utils.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(size_t, strcspn, (const char *src, const char *segment)) {
  return internal::complementary_span(src, segment);
}

} // namespace __llvm_libc