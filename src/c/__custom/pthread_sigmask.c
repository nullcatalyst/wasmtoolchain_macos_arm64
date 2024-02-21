#include <signal.h>

#include "src/c/__custom/panic.h"

int pthread_sigmask(int how, const sigset_t* set, sigset_t* oldset) { __WASM_PANIC(); }
