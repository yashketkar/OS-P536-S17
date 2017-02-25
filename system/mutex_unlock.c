/* mutex_unlock.c - mutex_unlock */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  mutex_unlock  -  Unlock Mutex
 *------------------------------------------------------------------------
 */
syscall mutex_unlock(mutex_t* lock)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();
	
	// if (isbadsem(semid) || semtab[semid].sstate == S_FREE) {
	// 	restore(mask);
	// 	return SYSERR;
	// }

	lock->lock = 0;

	restore(mask);
	return 0;
}
