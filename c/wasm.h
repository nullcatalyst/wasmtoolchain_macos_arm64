#ifndef WASM_TOOLCHAIN_WASM_H_
#define WASM_TOOLCHAIN_WASM_H_

#if defined(__wasm__)

#define WASM_IMPORT($module, $name) __attribute__((import_module($module), import_name($name)))
#define WASM_EXPORT($name) __attribute__((export_name($name)))

#else  // defined(__wasm__)

#define WASM_IMPORT($module, $name)
#define WASM_EXPORT($name)

#endif  // !defined(__wasm__)

#if defined(__cplusplus)
extern "C" {
#endif  // defined(__cplusplus)

WASM_IMPORT("console", "error")
void _console_error_impl(const char* msg_start, const char* msg_end);

#if defined(__cplusplus)
}  // extern "C"
#endif  // defined(__cplusplus)

#if !defined(WASM_PRINT_PANIC)
#define WASM_PRINT_PANIC 1
#endif  // !WASM_PRINT_PANIC

#if WASM_PRINT_PANIC

#define __WASM_PANIC_IMPL(msg)                                                                     \
    do {                                                                                           \
        const char $msg_prefix[]    = "aborting: unimplemented function call: ";                   \
        char       $msg_buffer[512] = {0};                                                         \
        __builtin_memcpy($msg_buffer, $msg_prefix, __builtin_strlen($msg_prefix));                 \
        __builtin_memcpy($msg_buffer + __builtin_strlen($msg_prefix), msg, __builtin_strlen(msg)); \
        _console_error_impl($msg_buffer, $msg_buffer + __builtin_strlen($msg_buffer));             \
        __builtin_trap();                                                                          \
    } while (0)

#define __WASM_PANIC() __WASM_PANIC_IMPL(__FUNCTION__)

#else  // WASM_PRINT_PANIC

#define __WASM_PANIC() __builtin_trap()

#endif  // !WASM_PRINT_PANIC

#endif  // WASM_TOOLCHAIN_WASM_H_
