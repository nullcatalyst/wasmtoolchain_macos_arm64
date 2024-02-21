#include <sys/statvfs.h>

int statvfs(const char* restrict path, struct statvfs* restrict buf) { __builtin_trap(); }

int fstatvfs(int fd, struct statvfs* buf) { __builtin_trap(); }
