/* cond_signal.c - cond_signal */

#include <xinu.h>

syscall cond_signal( cond_t* cv )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Wake up at least one of the processes waiting on the condition variable.
	
	restore(mask);
	return cv->val;
}
