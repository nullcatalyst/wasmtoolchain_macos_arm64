#include <stdint.h>

#if !defined(__wasm__)
#error "This file is for WebAssembly target only"
#endif

#if !__has_builtin(__builtin_wasm_memory_size) || !__has_builtin(__builtin_wasm_memory_grow)
#error "WebAssembly builtin memory instructions are required"
#endif

void* sbrk(intptr_t increment) {
    intptr_t before = __builtin_wasm_memory_size(0) << 16;
    __builtin_wasm_memory_grow(0, increment >> 16);
    return (void*)before;
}
