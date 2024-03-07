//===-- Implementation of ftell -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/ftell.h"
// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION

#include "c/std/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(long, ftell, (::FILE * stream)) {
  // auto result = reinterpret_cast<__llvm_libc::File *>(stream)->tell();
  // if (!result.has_value()) {
  //   libc_errno = result.error();
  //   return -1;
  // }
  // return result.value();
  __WASM_PANIC();
}

} // namespace __llvm_libc