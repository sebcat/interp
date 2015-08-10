#include "syscalls.h"

long s_write(int fd, const void *buf, unsigned long size)
{
    long ret;
	asm volatile(
		"syscall"
		: "=a" (ret)
		: "r"(__NR_write), "D"(fd), "S"(buf), "d"(size)
		: "cc", "rcx", "r11", "memory");
	return ret;
}

void s_exit(int status) {
	asm volatile(
		"syscall"
		: /* no output */
		: "r"(__NR_exit), "D"(status)
		: "cc", "rcx", "r11", "memory");
	__builtin_unreachable();
}

