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

/* stdlib.h */
int puts(const char *buf);
void itoa(int val, char *buf);

/* string.h */
size_t strlen(const char *string);
void _strcpy(char *dst, char *src);
void _strcat(char *dst, char *src);

#endif