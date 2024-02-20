#include <sys/statvfs.h>

int statvfs(const char* restrict path, struct statvfs* restrict buf) { return 0; }
int fstatvfs(int fd, struct statvfs* buf) { return 0; }
