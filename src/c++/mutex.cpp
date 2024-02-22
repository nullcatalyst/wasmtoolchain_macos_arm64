#include <__config>
#include <mutex>
#include <shared_mutex>

// All of these mutex operations are going to be no-ops because, while WebAssembly is slowly getting
// support for threads / shared memory / atomics, we are just going to assume that we aren't using
// those.

_LIBCPP_BEGIN_NAMESPACE_STD

// Shared Mutex Base

__shared_mutex_base::__shared_mutex_base() {}

void __shared_mutex_base::lock() {}

bool __shared_mutex_base::try_lock() { return true; }

void __shared_mutex_base::unlock() {}

void __shared_mutex_base::lock_shared() {}

bool __shared_mutex_base::try_lock_shared() { return true; }

void __shared_mutex_base::unlock_shared() {}

// Regular Mutex

mutex::~mutex() {}

void mutex::lock() {}

bool mutex::try_lock() _NOEXCEPT { return true; }

void mutex::unlock() _NOEXCEPT {}

// Recursive Mutex

recursive_mutex::recursive_mutex() {}

recursive_mutex::~recursive_mutex() {}

void recursive_mutex::lock() {}

bool recursive_mutex::try_lock() _NOEXCEPT { return true; }

void recursive_mutex::unlock() _NOEXCEPT {}

// Call Once

void __call_once(volatile once_flag::_State_type& flag, void* arg, void (*func)(void*)) {
    if (flag == 0) {
        flag = 1;
        func(arg);
        flag = ~once_flag::_State_type(0);
    }
}

_LIBCPP_END_NAMESPACE_STD
