#include <signal.h>

// None of these attempt to be actual implementations, they just return 0 or NULL.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

int kill(pid_t, int) { return 0; }
int killpg(pid_t, int) { return 0; }
int pthread_kill(pthread_t, int) { return 0; }
int pthread_sigmask(int, const sigset_t*, sigset_t*) { return 0; }
int raise(int) { return 0; }
int sigaction(int, const struct sigaction* restrict, struct sigaction* restrict) { return 0; }
// int sigaddset(sigset_t*, int) { return 0; }
int sigaltstack(const stack_t* restrict, stack_t* restrict) { return 0; }
// int sigdelset(sigset_t*, int) { return 0; }
// int sigemptyset(sigset_t*) { return 0; }
// int sigfillset(sigset_t*) { return 0; }
int sighold(int) { return 0; }
int sigignore(int) { return 0; }
int siginterrupt(int, int) { return 0; }
// int sigismember(const sigset_t*, int) { return 0; }
int sigpause(int) { return 0; }
int sigpending(sigset_t*) { return 0; }
int sigprocmask(int, const sigset_t* restrict, sigset_t* restrict) { return 0; }
int sigqueue(pid_t, int, const union sigval) { return 0; }
int sigrelse(int) { return 0; }
int sigsuspend(const sigset_t*) { return 0; }
int sigtimedwait(const sigset_t* restrict, siginfo_t* restrict, const struct timespec* restrict) {
    return 0;
}
int sigwait(const sigset_t* restrict, int* restrict) { return 0; }
int sigwaitinfo(const sigset_t* restrict, siginfo_t* restrict) { return 0; }
