#include <fcntl.h>

#include "src/wasm.h"

int fcntl(int fd, int cmd, ... /* arg */) { __WASM_PANIC(); }
