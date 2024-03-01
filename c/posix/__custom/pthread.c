#include <pthread.h>

#include "c/wasm.h"

int pthread_create(pthread_t* restrict thread, const pthread_attr_t* restrict attr,
                   void* (*start_routine)(void*), void* restrict arg) {
    start_routine(arg);
    // __WASM_PANIC();
}

int pthread_join(pthread_t thread, void** retval) { __WASM_PANIC(); }

int pthread_setspecific(pthread_key_t key, const void* value) { __WASM_PANIC(); }

int pthread_attr_init(pthread_attr_t* attr) { __WASM_PANIC(); }

int pthread_attr_destroy(pthread_attr_t* attr) { __WASM_PANIC(); }

int pthread_key_create(pthread_key_t* key, void (*destructor)(void*)) { __WASM_PANIC(); }
