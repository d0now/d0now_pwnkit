/*
 * TINYLIBC: util_common.h
 * d0now @ stealien
 *
 * Common function handling codes.
*/

#ifndef _UTIL_COMMON_H_
#define _UTIL_COMMON_H_

#include <syscall_common.h>
#include <syscall_vfs.h>

size_t strlen(const char *string);
int puts(const char *buf);

#endif