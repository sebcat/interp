#include "interp.h"
#include "syscalls.h"

// eval next bytecode
#define NEXT goto *syms[*pc++]

void eval(unsigned char *pc) {
	// bytecode symbol table, must correspond to OP_* defines in interp.h
	// Requires https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html
	static void *syms[] = {&&EXIT, &&PRINT};

	NEXT;
	PRINT:
		#define DUMMYSTR "trololo\n"
		s_write(STDOUT_FILENO, DUMMYSTR, sizeof(DUMMYSTR)-1);
		NEXT;
	EXIT:
		s_exit(0);
	  __builtin_unreachable();
}

