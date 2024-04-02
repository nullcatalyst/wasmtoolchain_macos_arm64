#include <new>

namespace std { // purposefully not versioned

// static constinit std::new_handler __new_handler = nullptr;

new_handler set_new_handler(new_handler handler) noexcept { return nullptr; }

new_handler get_new_handler() noexcept { return nullptr; }

} // namespace std
