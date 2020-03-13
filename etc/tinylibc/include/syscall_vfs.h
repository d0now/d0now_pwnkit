/*
 * TINYLIBC: syscall_vfs.h
 * d0now @ stealien
 *
 * VFS system call handling codes.
*/

#ifndef _SYSCALL_VFS_H_
#define _SYSCALL_VFS_H_

#include <sys/syscall.h> /* For system call numbers */
#include <sys/types.h>   /* For types */

extern int open(const char *pathname, int flags);
extern ssize_t read(int fd, void *buf, size_t count);
extern ssize_t write(int fd, const void *buf, size_t count);
extern int close(int fd);

#endif