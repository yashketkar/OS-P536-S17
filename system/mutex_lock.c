/* mutex_lock.c - mutex_lock */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  mutex_lock  -  Lock Mutex
 *------------------------------------------------------------------------
 */
syscall mutex_lock(mutex_t* lock)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();
	
	// if (isbadsem(semid) || semtab[semid].sstate == S_FREE) {
	// 	restore(mask);
	// 	return SYSERR;
	// }

    while (TestAndSet(&(lock->lock)) == 1);

	restore(mask);
	return 0;
}
