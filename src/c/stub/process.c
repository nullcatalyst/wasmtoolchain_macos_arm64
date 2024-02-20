#include <stdlib.h>

char* getenv(const char* name) { return (char*)0; }
int   setenv(const char* name, const char* value, int overwrite) { return 0; }
int   unsetenv(const char* name) { return 0; }
int   putenv(char* string) { return 0; }
int   clearenv(void) { return 0; }
