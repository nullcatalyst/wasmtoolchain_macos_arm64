#include <sys/mman.h>

// None of these attempt to be actual implementations, they just return 0 or NULL.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset) {
    return (void*)0;
}
int munmap(void* addr, size_t length) { return 0; }

int posix_madvise(void* addr, size_t len, int advice) { return 0; }
