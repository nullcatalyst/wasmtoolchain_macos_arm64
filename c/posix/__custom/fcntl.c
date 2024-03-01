#include <fcntl.h>

#include "c/wasm.h"

int fcntl(int fd, int cmd, ... /* arg */) { __WASM_PANIC(); }
