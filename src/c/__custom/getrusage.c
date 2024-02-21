#include <sys/resource.h>

#include "src/c/__custom/panic.h"

int getrusage(int who, struct rusage* usage) { __WASM_PANIC(); }
