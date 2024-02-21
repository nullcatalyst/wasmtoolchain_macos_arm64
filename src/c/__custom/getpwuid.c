#include <pwd.h>
#include <stddef.h>

struct passwd* getpwuid(uid_t uid) { __builtin_trap(); }

int getpwuid_r(uid_t uid, struct passwd* pwd, char* buffer, size_t bufsize,
               struct passwd** result) {
    __builtin_trap();
}
