#ifndef __INTERP_H
#define __INTERP_H

// opcodes, must correspond to the indices in the bytecode symbol table
#define OP_DONE  0
#define OP_PRINT 1

void eval(unsigned char *pc) __attribute__((noreturn));

#endif

