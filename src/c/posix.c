#include <sys/stat.h>
#include <unistd.h>

// None of these attempt to be actual implementations, they just return 0 or NULL.
// This is essentially here entirely to make linker issues go away.
// Please test to verify that that works well enough for your own use case.

// #include <sys/stat.h>
int    chmod(const char*, mode_t) { return 0; }
int    fchmod(int, mode_t) { return 0; }
int    fstat(int, struct stat*) { return 0; }
int    lstat(const char* restrict, struct stat* restrict) { return 0; }
int    mkdir(const char*, mode_t) { return 0; }
int    mkfifo(const char*, mode_t) { return 0; }
int    mknod(const char*, mode_t, dev_t) { return 0; }
int    stat(const char* restrict, struct stat* restrict) { return 0; }
mode_t umask(mode_t) { return 0; }

// #include <unistd.h>
int      access(const char*, int) { return 0; }
unsigned alarm(unsigned) { return 0; }
int      chdir(const char*) { return 0; }
int      chown(const char*, uid_t, gid_t) { return 0; }
int      close(int) { return 0; }
size_t   confstr(int, char*, size_t) { return 0; }

char* crypt(const char*, const char*) { return (char*)0; }
char* ctermid(char*) { return (char*)0; }
int   dup(int) { return 0; }

int  dup2(int, int) { return 0; }
void encrypt(char[64], int) { return; }
int  execl(const char*, const char*, ...) { return 0; }
int  execle(const char*, const char*, ...) { return 0; }
int  execlp(const char*, const char*, ...) { return 0; }
int  execv(const char*, char* const[]) { return 0; }
int  execve(const char*, char* const[], char* const[]) { return 0; }
int  execvp(const char*, char* const[]) { return 0; }
// void    _exit(int); //< Defined in src/c/exit.c
int     fchown(int, uid_t, gid_t) { return 0; }
int     fchdir(int) { return 0; }
int     fdatasync(int) { return 0; }
pid_t   fork(void) { return 0; }
long    fpathconf(int, int) { return 0; }
int     fsync(int) { return 0; }
int     ftruncate(int, off_t) { return 0; }
char*   getcwd(char*, size_t) { return (char*)0; }
gid_t   getegid(void) { return 0; }
uid_t   geteuid(void) { return 0; }
gid_t   getgid(void) { return 0; }
int     getgroups(int, gid_t[]) { return 0; }
long    gethostid(void) { return 0; }
int     gethostname(char*, size_t) { return 0; }
char*   getlogin(void) { return (char*)0; }
int     getlogin_r(char*, size_t) { return 0; }
int     getopt(int, char* const[], const char*) { return 0; }
pid_t   getpgid(pid_t) { return 0; }
pid_t   getpgrp(void) { return 0; }
pid_t   getpid(void) { return 0; }
pid_t   getppid(void) { return 0; }
pid_t   getsid(pid_t) { return 0; }
uid_t   getuid(void) { return 0; }
char*   getwd(char*) { return (char*)0; }
int     isatty(int) { return 0; }
int     lchown(const char*, uid_t, gid_t) { return 0; }
int     link(const char*, const char*) { return 0; }
int     lockf(int, int, off_t) { return 0; }
off_t   lseek(int, off_t, int) { return 0; }
int     nice(int) { return 0; }
long    pathconf(const char*, int) { return 0; }
int     pause(void) { return 0; }
int     pipe(int[2]) { return 0; }
ssize_t pread(int, void*, size_t, off_t) { return 0; }
ssize_t pwrite(int, const void*, size_t, off_t) { return 0; }
ssize_t read(int, void*, size_t) { return 0; }
ssize_t readlink(const char* restrict, char* restrict, size_t) { return 0; }
int     rmdir(const char*) { return 0; }
int     setegid(gid_t) { return 0; }
int     seteuid(uid_t) { return 0; }
int     setgid(gid_t) { return 0; }

int        setpgid(pid_t, pid_t) { return 0; }
pid_t      setpgrp(void) { return 0; }
int        setregid(gid_t, gid_t) { return 0; }
int        setreuid(uid_t, uid_t) { return 0; }
pid_t      setsid(void) { return 0; }
int        setuid(uid_t) { return 0; }
unsigned   sleep(unsigned) { return 0; }
void       swab(const void* restrict, void* restrict, ssize_t) { return; }
int        symlink(const char*, const char*) { return 0; }
void       sync(void) { return; }
long       sysconf(int) { return 0; }
pid_t      tcgetpgrp(int) { return 0; }
int        tcsetpgrp(int, pid_t) { return 0; }
int        truncate(const char*, off_t) { return 0; }
char*      ttyname(int) { return (char*)0; }
int        ttyname_r(int, char*, size_t) { return 0; }
useconds_t ualarm(useconds_t, useconds_t) { return 0; }
int        unlink(const char*) { return 0; }
int        usleep(useconds_t) { return 0; }
pid_t      vfork(void) { return 0; }
ssize_t    write(int, const void*, size_t) { return 0; }
