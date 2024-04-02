#include "mimalloc.h"

void* malloc(size_t size) { return mi_malloc(size); }
void* calloc(size_t count, size_t size) { return mi_calloc(count, size); }
void* realloc(void* ptr, size_t newsize) { return mi_realloc(ptr, newsize); }
void  free(void* ptr) { mi_free(ptr); }
