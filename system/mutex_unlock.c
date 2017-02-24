/* mutex_unlock.c - mutex_unlock */

#include <xinu.h>

syscall mutex_unlock( mutex_t* lock )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Release the lock.
	
	restore(mask);
	return lock->val;
}
