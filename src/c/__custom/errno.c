#include <errno.h>

int* __errno_location(void) {
    static int _errno = 0;
    return &_errno;
}
