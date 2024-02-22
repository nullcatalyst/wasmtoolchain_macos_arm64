#include <unistd.h>

#include "src/wasm.h"

unsigned int alarm(unsigned int seconds) { __WASM_PANIC(); }
