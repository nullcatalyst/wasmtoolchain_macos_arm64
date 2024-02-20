#include <string.h>

// Compare no more than N characters of S1 and S2, returning less than, equal to or greater than
// zero if S1 is lexicographically less than, equal to or greater than S2.
int strncmp(const char* s1, const char* s2, size_t n) {
    unsigned char c1 = '\0';
    unsigned char c2 = '\0';

    if (n >= 4) {
        size_t n4 = n >> 2;
        do {
            c1 = (unsigned char)*s1++;
            c2 = (unsigned char)*s2++;
            if (c1 == '\0' || c1 != c2) return c1 - c2;
            c1 = (unsigned char)*s1++;
            c2 = (unsigned char)*s2++;
            if (c1 == '\0' || c1 != c2) return c1 - c2;
            c1 = (unsigned char)*s1++;
            c2 = (unsigned char)*s2++;
            if (c1 == '\0' || c1 != c2) return c1 - c2;
            c1 = (unsigned char)*s1++;
            c2 = (unsigned char)*s2++;
            if (c1 == '\0' || c1 != c2) return c1 - c2;
        } while (--n4 > 0);
        n &= 3;
    }

    while (n > 0) {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 == '\0' || c1 != c2) return c1 - c2;
        n--;
    }

    return c1 - c2;
}
