/*
 * TINYLIBC: util_common.c
 * d0now @ stealien
 *
 * Common function handling codes.
*/

#include <syscall_common.h>
#include <syscall_vfs.h>
#include <util_common.h>

size_t strlen(const char *string) {

    int i=0;
    for (i=0 ; string[i] ; i++);
    return i;
}

int puts(const char *buf) {

    int len;

    len = strlen(buf);
    len = write(1, buf, len);

    return len; 
}