#ifndef __INTERP_H
#define __INTERP_H

// opcodes, must correspond to the indices in the bytecode symbol table
#define OP_DONE  0
#define OP_PRINT 1
#define OP_LIT   2

#define LITERAL(x) \
	OP_LIT, (x)&0xff, ((x)>>8)&0xff, ((x)>>16)&0xff, ((x)>>24)&0xff, \
			((x)>>32)&0xff, ((x)>>40)&0xff, ((x)>>48)&0xff, ((x)>>56)&0xff

void eval(unsigned char *pc);

#endif

