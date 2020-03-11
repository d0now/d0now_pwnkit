/*
 * TINYLIBC: internal.h
 * d0now @ stealien
 *
 * tinylibc internal handling codes.
*/

#ifndef _INTERNAL_H_
#define _INTERNAL_H_

/* Syscall defines */
typedef unsigned long scnum;
typedef unsigned long scarg;

/* Syscall argument handling */
#define SYSCALL_1(n, a1)                 \
        __syscall_internal((scnum)n, (scarg)a1, (scarg)0,  (scarg)0,  (scarg)0,  (scarg)0)
#define SYSCALL_2(n, a1, a2)             \
        __syscall_internal((scnum)n, (scarg)a1, (scarg)a2, (scarg)0,  (scarg)0,  (scarg)0)
#define SYSCALL_3(n, a1, a2, a3)         \
        __syscall_internal((scnum)n, (scarg)a1, (scarg)a2, (scarg)a3, (scarg)0,  (scarg)0)
#define SYSCALL_4(n, a1, a2, a3, a4)     \
        __syscall_internal((scnum)n, (scarg)a1, (scarg)a2, (scarg)a3, (scarg)a4, (scarg)0)
#define SYSCALL_5(n, a1, a2, a3, a4, a5) \
        __syscall_internal((scnum)n, (scarg)a1, (scarg)a2, (scarg)a3, (scarg)a4, (scarg)a5)

#endif