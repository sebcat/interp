// bytecode interpreter for Linux on amd64 targeting clang
// clang -o bc -Os -s -nostdlib -mstackrealign bytecode.c
// without -mstackrealign we need to manually align the stack to a
// 16 byte boundary in our _start function

#include "interp.h"

void _start() {
	unsigned char program[] = {OP_PRINT,OP_PRINT,OP_PRINT,OP_PRINT,OP_DONE};
	eval(program);
}

