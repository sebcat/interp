// bytecode interpreter for Linux on amd64 targeting clang
// clang -o bc -Os -s -nostdlib -mstackrealign bytecode.c
// without -mstackrealign we need to manually align the stack to a
// 16 byte boundary in our _start function

#include "interp.h"
#include "syscalls.h"

void _start() {
	unsigned char program[] = {
		LITERAL((unsigned long)"Hello, "),
		LITERAL(sizeof("Hello, ")-1),
		OP_PRINT,
		LITERAL((unsigned long)"World!\n"),
		LITERAL(sizeof("World!\n")-1),
		OP_PRINT,
		OP_DONE
	};

	eval(program);
	s_exit(0);
}

