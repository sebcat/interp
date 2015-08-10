// bytecode interpreter for Linux on amd64 targeting clang
// clang -o bc -Os -s -nostdlib -mstackrealign bytecode.c
// without -mstackrealign we need to manually align the stack to a
// 16 byte boundary in our _start function

#include "interp.h"
#include "syscalls.h"

void _start() {
	static const unsigned char *program = (const unsigned char *)
		OP_STR "\x0eHello, World!\n"
		OP_PRINT
		OP_DONE;

	eval(program);
	s_exit(0);
}

