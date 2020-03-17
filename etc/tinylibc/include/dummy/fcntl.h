/*
 * TINYLIBC: fcntl.h
 * d0now @ stealien
*/

#ifndef _FCNTL_H_
#define _FCNTL_H_

/* open() flags */
#define O_RDONLY    0x0000
#define O_WRONLY    0x0001
#define O_RDWR      0x0002

/* fcntl() commands */
#define F_DUPFD     0x00
#define F_GETFD     0x01
#define F_SETFD     0x02
#define F_SETFL     0x04

#endif