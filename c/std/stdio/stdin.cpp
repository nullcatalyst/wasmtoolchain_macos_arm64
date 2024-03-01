//===-- Definition of the global stdin object -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// #include "c/std/__support/File/file.h"

#include <stdio.h>

// extern "C" FILE *stdin;
extern "C" FILE *const stdin;
