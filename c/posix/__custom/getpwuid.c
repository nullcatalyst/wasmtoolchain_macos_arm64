#include <pwd.h>
#include <stddef.h>

#include "c/wasm.h"

struct passwd* getpwuid(uid_t uid) { __WASM_PANIC(); }

int getpwuid_r(uid_t uid, struct passwd* pwd, char* buffer, size_t bufsize,
               struct passwd** result) {
    __WASM_PANIC();
}
