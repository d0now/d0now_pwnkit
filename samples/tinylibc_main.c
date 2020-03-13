/*
 * Testing code for tinylibc
*/

#include <syscall_common.h>
#include <syscall_vfs.h>
#include <util_common.h>

int _start(void) {
    
    puts("Hello, World!");

    return 0;
}