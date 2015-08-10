#include "interp.h"
#include "syscalls.h"

// eval next bytecode
#define NEXT goto *syms[*pc++]

#define PSTACK_SIZE 32
#define PSTACK_POP() *--tos
#define PSTACK_PEEK() *(tos-1)
#define PSTACK_PUSH(x) (*tos++=(x))

// Beware: No over-/underflow checks for pstack (may or may not
// change in the future). Also no opcode validation. Code is assumed
// to be correct.

void eval(const unsigned char *pc) {
	// bytecode symbol table, must correspond to OP_* defines in interp.h
	// Requires https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html
	static void *syms[] = {&&DONE, &&PRINT, &&LIT, &&STR, &&DEC, &&JNZ};

	// parameter stack and TOS-pointer
	unsigned long pstack[PSTACK_SIZE], *tos = pstack;

	// temporary cells for storing parameters
	unsigned long p0, p1;
	long sp0;

	NEXT;
	LIT:
		p0 = *(unsigned long *)pc;
		pc += sizeof(unsigned long);
		PSTACK_PUSH(p0);
		NEXT;
	STR:
		p1 = (unsigned long)*pc++;
		p0 = (unsigned long)pc;
		pc += p1;
		PSTACK_PUSH(p0);
		PSTACK_PUSH(p1);
		NEXT;
	PRINT:
		p1 = PSTACK_POP();
		p0 = PSTACK_POP();
		s_write(STDOUT_FILENO, (void *)p0, p1);
		NEXT;
	DEC:
		PSTACK_PEEK() -= 1;
		NEXT;
	JNZ:
		if (PSTACK_PEEK() != 0) {
			// TOS is *not* consumed when the branch is taken
			sp0 = *(long *)pc;
			pc += sp0;
		} else {
			// TOS is consumed when the branch is not taken
			(void)PSTACK_POP();
			pc += sizeof(unsigned long);
		}
		NEXT;
	DONE:
		return;
}

