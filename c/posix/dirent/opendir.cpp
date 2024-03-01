//===-- Implementation of opendir -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "opendir.h"

// #include "c/std/__support/File/dir.h"
#include "c/std/__support/common.h"
#include "c/std/errno/libc_errno.h"

#include <dirent.h>

namespace __llvm_libc {

LLVM_LIBC_FUNCTION(::DIR *, opendir, (const char *name)) {
  // auto dir = Dir::open(name);
  // if (!dir) {
  //   libc_errno = dir.error();
  //   return nullptr;
  // }
  // return reinterpret_cast<DIR *>(dir.value());
  return nullptr;
}

} // namespace __llvm_libc
