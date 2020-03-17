/*
 * TINYLIBC: syscall_vfs.c
 * d0now @ stealien
 *
 * VFS system call handling codes.
*/

#include <syscall_vfs.h>

int open(const char *pathname, int flags) {
    return SYSCALL_2(SYS_open, pathname, flags);
}

ssize_t read(int fd, void *buf, size_t count) {
    return SYSCALL_3(SYS_read, fd, buf ,count);
}

ssize_t write(int fd, const void *buf, size_t count) {
    return SYSCALL_3(SYS_write, fd, buf ,count);
}

int close(int fd) {
    return SYSCALL_1(SYS_close, fd);
}

inline int fcntl(unsigned int fd, unsigned int cmd, unsigned long arg) {
    return (int)SYSCALL_3(SYS_fcntl, fd, cmd, arg);
}