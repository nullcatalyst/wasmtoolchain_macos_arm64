#include <signal.h>

#include "src/wasm.h"

int pthread_sigmask(int how, const sigset_t* set, sigset_t* oldset) { __WASM_PANIC(); }
