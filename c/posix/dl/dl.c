#include <dlfcn.h>

#include "c/wasm.h"

int   dlclose(void*) { __WASM_PANIC(); }
char* dlerror(void) { __WASM_PANIC(); }
void* dlopen(const char*, int) { __WASM_PANIC(); }
void* dlsym(void* __restrict, const char* __restrict) { __WASM_PANIC(); }

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

int dladdr(const void*, Dl_info*) { __WASM_PANIC(); }
int dlinfo(void*, int, void*) { __WASM_PANIC(); }

#endif  // defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
