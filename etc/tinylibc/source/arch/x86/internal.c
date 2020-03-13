/*
 * TINYLIBC: internal.c
 * d0now @ stealien
 *
 * tinylibc internal handling codes.
*/

#include <internal.h>

long __syscall_internal(scnum __number,
                        scarg a1, scarg a2, scarg a3, scarg a4, scarg a5) {

    long ret = -1;

    asm __volatile__ (
        "mov %1, %%eax\n"
        "mov %2, %%ebx\n"
        "mov %3, %%ecx\n"
        "mov %4, %%edx\n"
        "mov %5, %%esi\n"
        "mov %6, %%edi\n"
        "int $0x80\n"
        "mov %%eax, %0\n"
    : /* output */ "=r" (ret)
    : /* input  */ "m" (__number), "m" (a1), "m" (a2), "m" (a3), "m" (a4), "m" (a5));

    return ret;
}