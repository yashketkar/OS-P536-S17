/* cond_wait.c - cond_wait */

#include <xinu.h>

syscall cond_wait( cond_t* cv, mutex_t* lock )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Wait on the condition variable. 
	//While the process is waiting the lock should be released so that other processes may obtain it.

	restore(mask);
	return cv->val;
}
