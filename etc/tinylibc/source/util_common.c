/*
 * TINYLIBC: util_common.c
 * d0now @ stealien
 *
 * Common function handling codes.
*/

#include <util_common.h>

int puts(const char *buf) {

    int len;

    len = strlen(buf);
    len = write(1, buf, len);
    len += write(1, "\n", 1);

    return len; 
}

void itoa(int val, char *buf) {

    char tmp[256];
    int i, j, sign;

    if ((sign = val) < 0)
        val = - val;

    i = 0;
    do {
        tmp[i++] = val % 10 + '0';
    } while ((val /= 10) > 0);

    if (sign < 0)
        tmp[i++] = '-';

    for (j=0 ; j<i ; j++)
        buf[j] = tmp[i-j-1];

    buf[j] = '\0';
}

size_t strlen(const char *string) {

    int i=0;
    for (i=0 ; string[i] ; i++);
    return i;
}

void _strcpy(char *dst, char *src) {
    while (*dst++ = *src++);
}

void _strcat(char *dst, char *src) {
    while (*dst++);
    dst--;
    while (*dst++ = *src++);
}
