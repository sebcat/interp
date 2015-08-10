#ifndef __SYSCALLS_H
#define __SYSCALLS_H

#define __NR_write 1
#define __NR_exit  60
#define STDOUT_FILENO 1

void s_exit(int status) __attribute__((noreturn));
long s_write(int fd, const void *buf, unsigned long size);

#endif
