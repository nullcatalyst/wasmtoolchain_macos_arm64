//===-- Implementation of toupper------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/ctype/toupper.h"
#include "src/c/__support/ctype_utils.h"

#include "src/c/__support/common.h"

namespace __llvm_libc {

// TODO: Currently restricted to default locale.
// These should be extended using locale information.
LLVM_LIBC_FUNCTION(int, toupper, (int c)) {
  if (internal::islower(c))
    return c - ('a' - 'A');
  return c;
}

} // namespace __llvm_libc