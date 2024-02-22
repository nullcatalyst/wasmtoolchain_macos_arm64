#include <sys/resource.h>

#include "src/wasm.h"

int getrusage(int who, struct rusage* usage) { __WASM_PANIC(); }
