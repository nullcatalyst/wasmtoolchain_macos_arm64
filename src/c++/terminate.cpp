#include <cstdlib>

namespace std {  // purposefully not using versioning namespace

_LIBCPP_NORETURN void terminate() _NOEXCEPT { abort(); }

}  // namespace std
