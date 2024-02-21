//===-- Utilities for trigonometric functions -------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_MATH_GENERIC_RANGE_REDUCTION_H
#define LLVM_LIBC_SRC_MATH_GENERIC_RANGE_REDUCTION_H

#include "src/c/__support/FPUtil/FPBits.h"
#include "src/c/__support/FPUtil/multiply_add.h"
#include "src/c/__support/FPUtil/nearest_integer.h"
#include "src/c/__support/common.h"

namespace __llvm_libc {

namespace generic {

static constexpr uint32_t FAST_PASS_BOUND = 0x4a80'0000U; // 2^22

static constexpr int N_ENTRIES = 8;

// We choose to split bits of 32/pi into 28-bit precision pieces, so that the
// product of x * THIRTYTWO_OVER_PI_28[i] is exact.
// These are generated by Sollya with:
// > a1 = D(round(32/pi, 28, RN)); a1;
// > a2 = D(round(32/pi - a1, 28, RN)); a2;
// > a3 = D(round(32/pi - a1 - a2, 28, RN)); a3;
// > a4 = D(round(32/pi - a1 - a2 - a3, 28, RN)); a4;
// ...
static constexpr double THIRTYTWO_OVER_PI_28[N_ENTRIES] = {
    0x1.45f306ep+3,   -0x1.b1bbeaep-28,  0x1.3f84ebp-57,    -0x1.7056592p-87,
    0x1.c0db62ap-116, -0x1.4cd8778p-145, -0x1.bef806cp-174, 0x1.63abdecp-204};

// Exponents of the least significant bits of the corresponding entries in
// THIRTYTWO_OVER_PI_28.
static constexpr int THIRTYTWO_OVER_PI_28_LSB_EXP[N_ENTRIES] = {
    -24, -55, -81, -114, -143, -170, -200, -230};

// Return k and y, where
//   k = round(x * 16 / pi) and y = (x * 16 / pi) - k.
LIBC_INLINE int64_t small_range_reduction(double x, double &y) {
  double prod = x * THIRTYTWO_OVER_PI_28[0];
  double kd = fputil::nearest_integer(prod);
  y = prod - kd;
  y = fputil::multiply_add(x, THIRTYTWO_OVER_PI_28[1], y);
  y = fputil::multiply_add(x, THIRTYTWO_OVER_PI_28[2], y);
  return static_cast<int64_t>(kd);
}

// Return k and y, where
//   k = round(x * 32 / pi) and y = (x * 32 / pi) - k.
// For large range, there are at most 2 parts of THIRTYTWO_OVER_PI_28
// contributing to the lowest 6 binary digits (k & 63).  If the least
// significant bit of x * the least significant bit of THIRTYTWO_OVER_PI_28[i]
// >= 64, we can completely ignore THIRTYTWO_OVER_PI_28[i].
LIBC_INLINE int64_t large_range_reduction(double x, int x_exp, double &y) {
  int idx = 0;
  y = 0;
  int x_lsb_exp_m4 = x_exp - fputil::FloatProperties<float>::MANTISSA_WIDTH;

  // Skipping the first parts of 32/pi such that:
  //   LSB of x * LSB of THIRTYTWO_OVER_PI_28[i] >= 32.
  while (x_lsb_exp_m4 + THIRTYTWO_OVER_PI_28_LSB_EXP[idx] > 5)
    ++idx;

  double prod_hi = x * THIRTYTWO_OVER_PI_28[idx];
  // Get the integral part of x * THIRTYTWO_OVER_PI_28[idx]
  double k_hi = fputil::nearest_integer(prod_hi);
  // Get the fractional part of x * THIRTYTWO_OVER_PI_28[idx]
  double frac = prod_hi - k_hi;
  double prod_lo = fputil::multiply_add(x, THIRTYTWO_OVER_PI_28[idx + 1], frac);
  double k_lo = fputil::nearest_integer(prod_lo);

  // Now y is the fractional parts.
  y = prod_lo - k_lo;
  y = fputil::multiply_add(x, THIRTYTWO_OVER_PI_28[idx + 2], y);
  y = fputil::multiply_add(x, THIRTYTWO_OVER_PI_28[idx + 3], y);

  return static_cast<int64_t>(k_hi) + static_cast<int64_t>(k_lo);
}

} // namespace generic

} // namespace __llvm_libc

#endif // LLVM_LIBC_SRC_MATH_GENERIC_RANGE_REDUCTION_H