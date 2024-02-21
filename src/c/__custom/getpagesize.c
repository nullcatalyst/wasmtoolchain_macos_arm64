#include <unistd.h>

int getpagesize(void) {
#ifdef PAGESIZE
    return PAGESIZE;
#else
    // WebAssembly uses a fixed size of 64KB for pages
    return 65536;
#endif
}
