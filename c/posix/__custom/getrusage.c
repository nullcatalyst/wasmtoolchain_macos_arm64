#include <sys/resource.h>

#include "c/wasm.h"

int getrusage(int who, struct rusage* usage) { __WASM_PANIC(); }
