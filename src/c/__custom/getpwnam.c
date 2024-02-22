#include <pwd.h>
#include <stddef.h>

#include "src/wasm.h"

struct passwd* getpwnam(const char* name) { __WASM_PANIC(); }

int getpwnam_r(const char* name, struct passwd* pwd, char* buf, size_t buflen,
               struct passwd** result) {
    __WASM_PANIC();
}
