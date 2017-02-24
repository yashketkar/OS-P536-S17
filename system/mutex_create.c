/* mutex_create.c - mutex_create */

#include <xinu.h>

syscall mutex_create( mutex_t* lock )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//Create a mutex and set its initial state.
	lock->val = 0;

	restore(mask);
	return lock->val;
}
