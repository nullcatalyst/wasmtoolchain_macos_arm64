#include <string.h>

char* strncpy(char* __restrict dest, const char* __restrict src, size_t n) {
    size_t i = 0;
    // Copy up until \0 is found.
    for (; i < n && src[i] != '\0'; ++i) dest[i] = src[i];
    // When n>strlen(src), n-strlen(src) \0 are appended.
    for (; i < n; ++i) dest[i] = '\0';
    return dest;
}
