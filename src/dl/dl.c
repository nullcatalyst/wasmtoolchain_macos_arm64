#include <dlfcn.h>

// None of these attempt to be actual implementations, they just return 0 or (char*)0.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

int   dlclose(void*) { __builtin_trap(); }
char* dlerror(void) { __builtin_trap(); }
void* dlopen(const char*, int) { __builtin_trap(); }
void* dlsym(void* __restrict, const char* __restrict) { __builtin_trap(); }

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

int dladdr(const void*, Dl_info*) { __builtin_trap(); }
int dlinfo(void*, int, void*) { __builtin_trap(); }

#endif  // defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
