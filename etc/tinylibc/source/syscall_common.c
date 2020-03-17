/*
 * TINYLIBC: syscall_common.c
 * d0now @ stealien
 *
 * Common system call handling codes.
*/

#include <syscall_common.h>

inline void exit(int status) {
    SYSCALL_1(SYS_exit, status);
}

inline int execve(const char *pathname, char *const argv[], char *const envp[]) {
    return (int)SYSCALL_3(SYS_execve, pathname, argv, envp);
}

inline int pipe(int *fildes) {
    return (int)SYSCALL_1(SYS_pipe, fildes);
}

#ifdef CONFIG_X86
void *mmap(void *addr, size_t len, int prot, int flags, int fd, int offset) {
    struct mmap_arg_struct arg = {
        .addr   = (unsigned long)addr,
        .len    = len,
        .prot   = prot,
        .flags  = flags,
        .fd     = fd,
        .offset = offset,
    };

    return (void *)SYSCALL_1(SYS_old_mmap, &arg);
}
#endif

#ifdef CONFIG_X64
void *mmap(void *addr, size_t len, int prot, int flags, int fd, int offset) {
    return (void *)SYSCALL_6(SYS_mmap, addr, len, prot, flags, fd, offset);
}
#endif