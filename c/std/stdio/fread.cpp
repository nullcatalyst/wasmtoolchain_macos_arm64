//===-- Implementation of fread -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/fread.h"
// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION

#include "c/std/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(size_t, fread,
                   (void *__restrict buffer, size_t size, size_t nmemb,
                    ::FILE *stream)) {
  // if (size == 0 || nmemb == 0)
  //   return 0;
  // auto result =
  //     reinterpret_cast<__llvm_libc::File *>(stream)->read(buffer, size * nmemb);
  // if (result.has_error())
  //   libc_errno = result.error;
  // return result.value / size;
  __WASM_PANIC();
}

} // namespace __llvm_libc
