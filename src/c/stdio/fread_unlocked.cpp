//===-- Implementation of fread_unlocked ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/c/stdio/fread_unlocked.h"
// #include "src/c/__support/File/file.h"
#include "src/c/__support/common.h" // LLVM_LIBC_FUNCTION

#include "src/c/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(size_t, fread_unlocked,
                   (void *__restrict buffer, size_t size, size_t nmemb,
                    ::FILE *stream)) {
  // if (size == 0 || nmemb == 0)
  //   return 0;
  // auto result = reinterpret_cast<__llvm_libc::File *>(stream)->read_unlocked(
  //     buffer, size * nmemb);
  // if (result.has_error())
  //   libc_errno = result.error;
  // return result.value / size;
  __WASM_PANIC();
}

} // namespace __llvm_libc
