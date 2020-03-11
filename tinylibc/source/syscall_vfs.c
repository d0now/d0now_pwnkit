/*
 * TINYLIBC: syscall_vfs.c
 * d0now @ stealien
 *
 * VFS system call handling codes.
*/

#include <internal.h>
#include <sys/syscall.h> /* For system call numbers */

inline int open(const char *pathname, int flags) {
    return SYSCALL_2(SYS_open, pathname, flags);
}

ssize_t read(int fd, void *buf, size_t count) {
    return SYSCALL_3(SYS_read, fd, buf ,count);
}

ssize_t write(int fd, const void *buf, size_t count) {
    return SYSCALL_3(SYS_write, fd, buf ,count);
}

inline int close(int fd) {
    return SYSCALL_1(SYS_close, fd);
}