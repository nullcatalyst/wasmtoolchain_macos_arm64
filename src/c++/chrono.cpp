#include <chrono>

#include "src/wasm.h"

WASM_IMPORT("time", "now_unix") uint64_t __time_now_unix();
WASM_IMPORT("time", "now_perf") double __time_now_perf();

_LIBCPP_BEGIN_NAMESPACE_STD

namespace chrono {

const bool system_clock::is_steady;

system_clock::time_point system_clock::now() noexcept {
    return system_clock::time_point(milliseconds(__time_now_unix()));
}

time_t system_clock::to_time_t(const time_point& t) noexcept {
    return time_t(duration_cast<seconds>(t.time_since_epoch()).count());
}

system_clock::time_point system_clock::from_time_t(time_t t) noexcept {
    return system_clock::time_point(seconds(t));
}

const bool steady_clock::is_steady;

steady_clock::time_point steady_clock::now() noexcept {
    return steady_clock::time_point(microseconds(static_cast<uint64_t>(1000 * __time_now_perf())));
}

}  // namespace chrono

_LIBCPP_END_NAMESPACE_STD
