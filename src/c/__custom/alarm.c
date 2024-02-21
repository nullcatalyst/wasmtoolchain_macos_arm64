#include <unistd.h>
#include "src/c/__custom/panic.h"

unsigned int alarm(unsigned int seconds) {
    __WASM_PANIC();
}
