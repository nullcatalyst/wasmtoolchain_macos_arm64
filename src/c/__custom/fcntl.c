#include <fcntl.h>

#include "src/c/__custom/panic.h"

int fcntl(int fd, int cmd, ... /* arg */) { __WASM_PANIC(); }
