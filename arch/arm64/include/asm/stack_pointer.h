#ifndef __ASM_STACK_POINTER_H
#define __ASM_STACK_POINTER_H

/*
 * how to get the current stack pointer in C
 *
 * Some versions of Clang do not reliably support "sp" as a global
 * register variable on AArch64, so read it explicitly via inline asm
 * on every use instead of binding a persistent register variable.
 */
#define current_stack_pointer					\
({								\
	unsigned long __csp;					\
	asm ("mov %0, sp" : "=r" (__csp));			\
	__csp;							\
})

#endif /* __ASM_STACK_POINTER_H */
