//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <__config>
#include <condition_variable>
#include <thread>

_LIBCPP_BEGIN_NAMESPACE_STD

condition_variable::~condition_variable() {}

void condition_variable::notify_one() noexcept {}

void condition_variable::notify_all() noexcept {}

void condition_variable::wait(unique_lock<mutex>& lk) noexcept {}

void condition_variable::__do_timed_wait(
    unique_lock<mutex>&                                           lk,
    chrono::time_point<chrono::system_clock, chrono::nanoseconds> tp) noexcept {}

void notify_all_at_thread_exit(condition_variable& cond, unique_lock<mutex> lk) {}

_LIBCPP_END_NAMESPACE_STD
