/*
 * TINYLIBC: syscall_vfs.h
 * d0now @ stealien
 *
 * VFS system call handling codes.
*/

inline int open(const char *pathname, int flags);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
inline int close(int fd);