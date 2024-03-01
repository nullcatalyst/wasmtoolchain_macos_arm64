#include <unistd.h>

int getpagesize(void) {
    // WebAssembly uses a fixed size of 64KiB for pages
    return 16 * 1024;
}
