#include <sys/wait.h>

pid_t wait(int* status) { return 0; }
pid_t wait3(int* _Nullable wstatus, int options, struct rusage* _Nullable rusage) { return 0; }
pid_t wait4(pid_t pid, int* _Nullable wstatus, int options, struct rusage* _Nullable rusage) {
    return 0;
}
