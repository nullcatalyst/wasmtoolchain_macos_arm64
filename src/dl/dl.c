#include <dlfcn.h>

// None of these attempt to be actual implementations, they just return 0 or (char*)0.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

int   dlclose(void*) { return 0; }
char* dlerror(void) { return (char*)0; }
void* dlopen(const char*, int) { return (void*)0; }
void* dlsym(void* __restrict, const char* __restrict) { return (void*)0; }

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

int dladdr(const void*, Dl_info*) { return 0; }
int dlinfo(void*, int, void*) { return 0; }

#endif  // defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
