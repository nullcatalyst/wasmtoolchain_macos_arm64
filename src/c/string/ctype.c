#include <ctype.h>

int isalpha(int c) {
    unsigned ch = c;
    return (ch | 32) - 'a' < 26;
}

int isdigit(int c) {
    unsigned ch = c;
    return (ch - '0') < 10;
}

int isxdigit(int c) {
    const unsigned ch = c;
    return isdigit(ch) || (ch | 32) - 'a' < 6;
}

int isalnum(int c) { return isalpha(c) || isdigit(c); }

int isgraph(int c) {
    unsigned ch = c;
    return 0x20 < ch && ch < 0x7f;
}

int islower(int c) {
    unsigned ch = c;
    return (ch - 'a') < 26;
}

int isupper(int c) {
    unsigned ch = c;
    return (ch - 'A') < 26;
}

int isspace(int c) {
    unsigned ch = c;
    return ch == ' ' || (ch - '\t') < 5;
}

int tolower(int c) {
    if (isupper(c)) return c + ('a' - 'A');
    return c;
}

int toupper(int c) {
    if (islower(c)) return c - ('a' - 'A');
    return c;
}
