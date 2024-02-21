//===-- Implementation of strerror ----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/string/strerror.h"
#include "src/c/__support/StringUtil/error_to_string.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(char *, strerror, (int err_num)) {
  return const_cast<char *>(get_error_string(err_num).data());
}

} // namespace __llvm_libc
