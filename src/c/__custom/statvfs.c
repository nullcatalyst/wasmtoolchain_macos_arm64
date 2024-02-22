#include <sys/statvfs.h>

#include "src/wasm.h"

int statvfs(const char* restrict path, struct statvfs* restrict buf) { __WASM_PANIC(); }

int fstatvfs(int fd, struct statvfs* buf) { __WASM_PANIC(); }
