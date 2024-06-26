//===-- Implementation of fputs -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/fputs.h"
#include "c/std/__support/CPP/string_view.h"
// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION

#include "c/std/errno/libc_errno.h"
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, fputs,
                   (const char *__restrict str, ::FILE *__restrict stream)) {
  // cpp::string_view str_view(str);

  // auto result = reinterpret_cast<__llvm_libc::File *>(stream)->write(
  //     str, str_view.size());
  // if (result.has_error())
  //   libc_errno = result.error;
  // size_t written = result.value;

  // if (str_view.size() != written) {
  //   // The stream should be in an error state in this case.
  //   return EOF;
  // }
  // return 0;
  __WASM_PANIC();
}

} // namespace __llvm_libc
