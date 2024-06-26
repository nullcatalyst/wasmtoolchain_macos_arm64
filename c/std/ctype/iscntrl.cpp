//===-- Implementation of iscntrl------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/ctype/iscntrl.h"

#include "c/std/__support/common.h"

namespace __llvm_libc {

// TODO: Currently restricted to default locale.
// These should be extended using locale information.
LLVM_LIBC_FUNCTION(int, iscntrl, (int c)) {
  const unsigned ch = static_cast<unsigned>(c);
  return static_cast<int>(ch < 0x20 || ch == 0x7f);
}

} // namespace __llvm_libc
