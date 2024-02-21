#include <pwd.h>
#include <stddef.h>

struct passwd* getpwnam(const char* name) { __builtin_trap(); }

int getpwnam_r(const char* name, struct passwd* pwd, char* buf, size_t buflen,
               struct passwd** result) {
    __builtin_trap();
}
