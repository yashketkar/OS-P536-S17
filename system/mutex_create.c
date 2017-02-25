/* mutex_create.c - mutex_create */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  mutex_create  -  Create Mutex
 *------------------------------------------------------------------------
 */
syscall mutex_create(mutex_t* lock)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();

	lock->lock = 0;

	restore(mask);
	return 0;
}