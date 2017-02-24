/* mutex_lock.c - mutex_lock */

#include <xinu.h>

syscall mutex_lock( mutex_t* lock )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Obtain the lock. 
	//If the lock is already held the process must wait. When the call returns the process must hold the lock.

	while(lock->hold);
	lock->hold = true;

	restore(mask);
	return 0;
}
