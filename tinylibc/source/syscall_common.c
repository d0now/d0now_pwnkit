/*
 * TINYLIBC: syscall_common.c
 * d0now @ stealien
 *
 * Common system call handling codes.
*/

#include <internal.h>
#include <syscall_common.h>

inline void exit(int status) {
    SYSCALL_1(SYS_exit, status);
}