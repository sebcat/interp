#ifndef __INTERP_H
#define __INTERP_H

// opcodes, must correspond to the indices in the bytecode symbol table
#define OP_DONE  "\x00"
#define OP_PRINT "\x01"
#define OP_LIT   "\x02"
#define OP_STR   "\x03"
#define OP_DEC   "\x04"
#define OP_JNZ   "\x05"

void eval(const unsigned char *pc);

#endif

