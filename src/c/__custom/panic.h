#pragma once

#include "src/wasm.h"

#if defined(__cplusplus)
extern "C" {
#endif

WASM_IMPORT("console", "error")
void _console_error_impl(const char* msg_start, const char* msg_end);

#if defined(__cplusplus)
}  // extern "C"
#endif

#if 0

#define __WASM_PANIC_IMPL(msg)                                        \
    do {                                                              \
        _console_error_impl(msg, msg + __builtin_strlen(msg)); \
        __builtin_trap();                                             \
    } while (0)

#define __WASM_PANIC() __WASM_PANIC_IMPL(__FUNCTION__)

#else

#define __WASM_PANIC() __builtin_trap()

#endif
