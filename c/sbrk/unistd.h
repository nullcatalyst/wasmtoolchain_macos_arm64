/* Stub include file to support malloc implementations. */

#include <stdint.h>

#define EINVAL 0
#define ENOMEM 0

#define sysconf(name) PAGESIZE
#define _SC_PAGESIZE

/* Declare sbrk. */
void* sbrk(intptr_t increment) __attribute__((__warn_unused_result__));
