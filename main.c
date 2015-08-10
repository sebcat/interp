// bytecode interpreter for Linux on amd64 targeting clang
// clang -o bc -Os -s -nostdlib -mstackrealign bytecode.c
// without -mstackrealign we need to manually align the stack to a
// 16 byte boundary in our _start function

#include "interp.h"
#include "syscalls.h"

void _start() {
	static const unsigned char *program = (const unsigned char *)
		/* 00000000 */ OP_LIT "\x0a\x00\x00\x00\x00\x00\x00\x00"
		/* 00000009 */ OP_STR "\x0eHello, World!\n"
		/* 00000019 */ OP_PRINT
		/* 0000001a */ OP_DEC
		/* 0000001b */ OP_JNZ "\xed\xff\xff\xff\xff\xff\xff\xff"
		/* 00000024 */ OP_DONE;

	eval(program);
	s_exit(0);
}

