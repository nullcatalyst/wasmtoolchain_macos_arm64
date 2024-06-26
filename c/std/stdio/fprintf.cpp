//===-- Implementation of fprintf -------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/fprintf.h"

// #include "c/std/__support/File/file.h"
#include "c/std/__support/common.h" // LLVM_LIBC_FUNCTION
#include "c/std/__support/arg_list.h"
// #include "c/std/stdio/printf_core/vfprintf_internal.h"

#include <stdarg.h>
#include <stdio.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, fprintf,
                   (::FILE *__restrict stream, const char *__restrict format,
                    ...)) {
  // va_list vlist;
  // va_start(vlist, format);
  // internal::ArgList args(vlist); // This holder class allows for easier copying
  //                                // and pointer semantics, as well as handling
  //                                // destruction automatically.
  // va_end(vlist);
  // int ret_val = printf_core::vfprintf_internal(stream, format, args);
  // return ret_val;
  __WASM_PANIC();
}

} // namespace __llvm_libc
