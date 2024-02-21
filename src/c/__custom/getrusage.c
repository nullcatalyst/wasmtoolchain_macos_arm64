#include <sys/resource.h>

int getrusage(int who, struct rusage* usage) { __builtin_trap(); }
