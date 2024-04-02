//===---------- Linux implementation of the POSIX clock_gettime function --===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "c/std/time/clock_gettime.h"

#include "c/std/__support/OSUtil/syscall.h" // For internal syscall function.
#include "c/std/__support/common.h"
#include "c/std/errno/libc_errno.h"
// #include "c/std/time/linux/clockGetTimeImpl.h"

// #include <sys/syscall.h> // For syscall numbers.
#include <time.h>

#include "c/wasm.h"
WASM_IMPORT("time", "now_unix") uint64_t __time_now_unix();
WASM_IMPORT("time", "now_perf") double __time_now_perf();

namespace LIBC_NAMESPACE {

LLVM_LIBC_FUNCTION(int, clock_gettime,
                   (clockid_t clockid, struct timespec *ts)) {
//   auto result = internal::clock_gettimeimpl(clockid, ts);

//   // A negative return value indicates an error with the magnitude of the
//   // value being the error code.
//   if (!result.has_value()) {
//     libc_errno = result.error();
//     return -1;
//   }
//   return 0;

    switch (clockid) {
        case CLOCK_REALTIME: {
            ts->tv_sec  = __time_now_unix();
            ts->tv_nsec = 0;
            return 0;
        }
        case CLOCK_MONOTONIC: {
            double now = __time_now_perf();
            ts->tv_sec  = now;
            ts->tv_nsec = (now - ts->tv_sec) * 1e9;
            return 0;
        }
        default:
            return -1;
    }
}

} // namespace LIBC_NAMESPACE
