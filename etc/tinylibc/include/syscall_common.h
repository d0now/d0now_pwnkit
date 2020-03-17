/*
 * TINYLIBC: syscall_common.h
 * d0now @ stealien
 *
 * Common system call handling codes.
*/

#ifndef _SYSCALL_COMMON_H_
#define _SYSCALL_COMMON_H_

#include <internal.h>
#include <sys/syscall.h>
#include <sys/types.h>

/* unistd.h */
void exit(int status);
inline int execve(const char *pathname, char *const argv[], char *const envp[]);

/* pipe.h */
inline int pipe(int *fildes);

/* mman.h */
void *mmap(void *addr, size_t len, int prot, int flags, int fd, int offset);

#endif