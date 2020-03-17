/*
 * TINYLIBC: sys/syscall.h
 * d0now @ stealien
*/

#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#ifdef CONFIG_X86
/*
 * x86 system calls
*/
#define SYS_exit        0x01
#define SYS_read        0x03
#define SYS_write       0x04
#define SYS_open        0x05
#define SYS_close       0x06
#define SYS_execve      0x0b
#define SYS_pipe        0x2a
#define SYS_fcntl       0x37
#define SYS_old_mmap    0x5a
#endif

#ifdef CONFIG_X64
/*
 * x64 system calls
*/
#define SYS_read        0x00
#define SYS_write       0x01
#define SYS_open        0x02
#define SYS_close       0x03
#define SYS_mmap        0x09
#define SYS_pipe        0x16
#define SYS_execve      0x3b
#define SYS_exit        0x3c
#define SYS_fcntl       0x48    
#endif

#endif /* _SYSCALL_H_ */