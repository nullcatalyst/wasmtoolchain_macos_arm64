#include <fcntl.h>

int fcntl(int fd, int cmd, ... /* arg */ ) {
    __builtin_trap();
}
