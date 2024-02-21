#include <unistd.h>

unsigned int alarm(unsigned int seconds) {
    __builtin_trap();
}
