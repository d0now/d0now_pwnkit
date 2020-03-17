/*
 * TINYLIBC: internal.c
 * d0now @ stealien
 *
 * tinylibc internal handling codes.
*/

#include <internal.h>

#ifdef CONFIG_X64

long __syscall_internal(scnum __number,
                        scarg a1, scarg a2, scarg a3, scarg a4, scarg a5, scarg a6) {

    long ret = -1;

    asm __volatile__ (
        "mov %1, %%rax\n"
        "mov %2, %%rdi\n"
        "mov %3, %%rsi\n"
        "mov %4, %%rdx\n"
        "mov %5, %%r10\n"
        "mov %6, %%r8\n"
        "mov %7, %%r9\n"
        "syscall\n"
        "mov %%rax, %0\n"
    : /* output */ "=r" (ret)
    : /* input  */ "m" (__number), "m" (a1), "m" (a2), "m" (a3), "m" (a4), "m" (a5), "m" (a6));

    return ret;
}

#endif