/*
 * TINYLIBC: sys/mman.h
 * d0now @ stealien
*/

#ifndef _MMAN_H_
#define _MMAN_H_

#ifdef CONFIG_X86
struct mmap_arg_struct {
    unsigned long addr;
    unsigned long len;
    unsigned long prot;
    unsigned long flags;
    unsigned long fd;
    unsigned long offset;
};
#endif

/* Protections */
#define PROT_READ       0x01    /* pages can be read */
#define PROT_WRITE      0x02    /* pages can be written */
#define PROT_EXEC       0x04    /* pages can be executed */

/* Flags */
#define MAP_SHARED      0x01
#define MAP_PRIVATE     0x02
#define MAP_FIXED       0x03
#define MAP_ANONYMOUS   0x20

#endif