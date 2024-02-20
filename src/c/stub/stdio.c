#include <stdio.h>

// None of these attempt to be actual implementations, they just return 0 or NULL.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

void clearerr(FILE*) { return; }
// char*  ctermid(char*) { return (char*)0; }
int    fclose(FILE*) { return 0; }
FILE*  fdopen(int, const char*) { return (FILE*)0; }
int    feof(FILE*) { return 0; }
int    ferror(FILE*) { return 0; }
int    fflush(FILE*) { return 0; }
int    fgetc(FILE*) { return 0; }
int    fgetpos(FILE* restrict, fpos_t* restrict) { return 0; }
char*  fgets(char* restrict, int, FILE* restrict) { return (char*)0; }
int    fileno(FILE*) { return 0; }
void   flockfile(FILE*) { return; }
FILE*  fopen(const char* restrict, const char* restrict) { return (FILE*)0; }
int    fprintf(FILE* restrict, const char* restrict, ...) { return 0; }
int    fputc(int, FILE*) { return 0; }
int    fputs(const char* restrict, FILE* restrict) { return 0; }
size_t fread(void* restrict, size_t, size_t, FILE* restrict) { return 0; }
FILE*  freopen(const char* restrict, const char* restrict, FILE* restrict) { return (FILE*)0; }
int    fscanf(FILE* restrict, const char* restrict, ...) { return 0; }
int    fseek(FILE*, long, int) { return 0; }
int    fseeko(FILE*, off_t, int) { return 0; }
int    fsetpos(FILE*, const fpos_t*) { return 0; }
long   ftell(FILE*) { return 0; }
off_t  ftello(FILE*) { return 0; }
int    ftrylockfile(FILE*) { return 0; }
void   funlockfile(FILE*) { return; }
size_t fwrite(const void* restrict, size_t, size_t, FILE* restrict) { return 0; }
int    getc(FILE*) { return 0; }
int    getchar(void) { return 0; }
// int    getc_unlocked(FILE*) { return 0; }
// int    getchar_unlocked(void) { return 0; }
char* gets(char*) { return (char*)0; }
int   pclose(FILE*) { return 0; }
void  perror(const char*) { return; }
FILE* popen(const char*, const char*) { return (FILE*)0; }
int   printf(const char* restrict, ...) { return 0; }
int   putc(int, FILE*) { return 0; }
int   putchar(int) { return 0; }
// int    putc_unlocked(int, FILE*) { return 0; }
// int    putchar_unlocked(int) { return 0; }
int  puts(const char*) { return 0; }
int  remove(const char*) { return 0; }
int  rename(const char*, const char*) { return 0; }
void rewind(FILE*) { return; }
int  scanf(const char* restrict, ...) { return 0; }
void setbuf(FILE* restrict, char* restrict) { return; }
int  setvbuf(FILE* restrict, char* restrict, int, size_t) { return 0; }
// int    snprintf(char* restrict, size_t, const char* restrict, ...) { return 0; }
// int    sprintf(char* restrict, const char* restrict, ...) { return 0; }
int   sscanf(const char* restrict, const char* restrict, ...) { return 0; }
char* tempnam(const char*, const char*) { return (char*)0; }
FILE* tmpfile(void) { return (FILE*)0; }
char* tmpnam(char*) { return (char*)0; }
int   ungetc(int, FILE*) { return 0; }
int   vfprintf(FILE* restrict, const char* restrict, va_list) { return 0; }
int   vfscanf(FILE* restrict, const char* restrict, va_list) { return 0; }
int   vprintf(const char* restrict, va_list) { return 0; }
int   vscanf(const char* restrict, va_list) { return 0; }
// int    vsnprintf(char* restrict, size_t, const char* restrict, va_list) { return 0; }
// int    vsprintf(char* restrict, const char* restrict, va_list) { return 0; }
int vsscanf(const char* restrict, const char* restrict, va_list arg) { return 0; }
