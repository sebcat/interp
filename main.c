// bytecode interpreter for Linux on amd64 targeting clang
// clang -o bc -Os -s -nostdlib -mstackrealign bytecode.c
// without -mstackrealign we need to manually align the stack to a
// 16 byte boundary in our _start function

#include "interp.h"
#include "syscalls.h"

void _start() {
	static const unsigned char *program = (const unsigned char *)
		/* 00000000 */ OP_LIT "\x0a\x00\x00\x00\x00\x00\x00\x00"
		/* 00000009 */ OP_DUP
		/* 0000000a */ OP_DOT
		/* 0000000b */ OP_DEC
		/* 0000000c */ OP_JNZ "\xfc"
		/* 0000000e */ OP_DONE;

	eval(program);
	s_exit(0);
}

