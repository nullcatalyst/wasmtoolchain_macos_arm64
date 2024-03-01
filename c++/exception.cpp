#include <exception>

namespace std {  // purposefully not using versioning namespace

bool uncaught_exception() _NOEXCEPT { return false; }

exception_ptr::~exception_ptr() noexcept { __builtin_trap(); }

}  // namespace std

_LIBCPP_BEGIN_NAMESPACE_STD

_LIBCPP_NORETURN _LIBCPP_EXPORTED_FROM_ABI void __throw_system_error(int         __ev,
                                                                     const char* __what_arg) {
    __builtin_trap();
}

_LIBCPP_END_NAMESPACE_STD
