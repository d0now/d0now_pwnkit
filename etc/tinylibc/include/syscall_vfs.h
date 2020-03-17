/*
 * TINYLIBC: syscall_vfs.h
 * d0now @ stealien
 *
 * VFS system call handling codes.
*/

#ifndef _SYSCALL_VFS_H_
#define _SYSCALL_VFS_H_

#include <internal.h>
#include <sys/syscall.h> /* For system call numbers */
#include <sys/types.h>   /* For types */

/* unistd.h */
extern int open(const char *pathname, int flags);
extern int close(int fd);
extern ssize_t read(int fd, void *buf, size_t count);
extern ssize_t write(int fd, const void *buf, size_t count);

/* fcntl.h */
inline int fcntl(unsigned int fd, unsigned int cmd, unsigned long arg);

#endif