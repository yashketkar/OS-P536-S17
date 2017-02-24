/* mutex_unlock.c - mutex_unlock */

#include <xinu.h>

syscall mutex_unlock( mutex_t* lock )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Release the lock.
	
	lock->hold = false;

	restore(mask);
	return 0;
}
