#include <unistd.h>

#include "c/wasm.h"

unsigned int alarm(unsigned int seconds) { __WASM_PANIC(); }
