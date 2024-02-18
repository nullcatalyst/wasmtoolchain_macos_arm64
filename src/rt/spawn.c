#include <spawn.h>

// None of these attempt to be actual implementations, they just return 0 or NULL.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

int posix_spawn(pid_t* __restrict, const char* __restrict, const posix_spawn_file_actions_t*,
                const posix_spawnattr_t* __restrict, char* const* __restrict,
                char* const* __restrict) {
    return 0;
}
int posix_spawnp(pid_t* __restrict, const char* __restrict, const posix_spawn_file_actions_t*,
                 const posix_spawnattr_t* __restrict, char* const* __restrict,
                 char* const* __restrict) {
    return 0;
}

int posix_spawnattr_init(posix_spawnattr_t*) { return 0; }
int posix_spawnattr_destroy(posix_spawnattr_t*) { return 0; }

int posix_spawnattr_setflags(posix_spawnattr_t*, short) { return 0; }
int posix_spawnattr_getflags(const posix_spawnattr_t* __restrict, short* __restrict) { return 0; }

int posix_spawnattr_setpgroup(posix_spawnattr_t*, pid_t) { return 0; }
int posix_spawnattr_getpgroup(const posix_spawnattr_t* __restrict, pid_t* __restrict) { return 0; }

int posix_spawnattr_setsigmask(posix_spawnattr_t* __restrict, const sigset_t* __restrict) {
    return 0;
}
int posix_spawnattr_getsigmask(const posix_spawnattr_t* __restrict, sigset_t* __restrict) {
    return 0;
}

int posix_spawnattr_setsigdefault(posix_spawnattr_t* __restrict, const sigset_t* __restrict) {
    return 0;
}
int posix_spawnattr_getsigdefault(const posix_spawnattr_t* __restrict, sigset_t* __restrict) {
    return 0;
}

int posix_spawnattr_setschedparam(posix_spawnattr_t* __restrict,
                                  const struct sched_param* __restrict) {
    return 0;
}
int posix_spawnattr_getschedparam(const posix_spawnattr_t* __restrict,
                                  struct sched_param* __restrict) {
    return 0;
}
int posix_spawnattr_setschedpolicy(posix_spawnattr_t*, int) { return 0; }
int posix_spawnattr_getschedpolicy(const posix_spawnattr_t* __restrict, int* __restrict) {
    return 0;
}

int posix_spawn_file_actions_init(posix_spawn_file_actions_t*) { return 0; }
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t*) { return 0; }

int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t* __restrict, int,
                                     const char* __restrict, int, mode_t) {
    return 0;
}
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t*, int) { return 0; }
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t*, int, int) { return 0; }
