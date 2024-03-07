//===-- Implementation of sprintf -------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/stdio/vsprintf.h"

#include "c/std/__support/CPP/limits.h"
#include "c/std/__support/arg_list.h"
#include "c/std/stdio/printf_core/printf_main.h"
#include "c/std/stdio/printf_core/writer.h"

#include <stdarg.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(int, vsprintf,
                   (char *__restrict buffer, const char *__restrict format,
                    va_list vlist)) {
  internal::ArgList args(vlist);

  printf_core::WriteBuffer wb(buffer, cpp::numeric_limits<size_t>::max());
  printf_core::Writer writer(&wb);

  int ret_val = printf_core::printf_main(&writer, format, args);
  wb.buff[wb.buff_cur] = '\0';
  return ret_val;
}

} // namespace __llvm_libc