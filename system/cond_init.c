	/* semcount.c - semcount */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  semcount  -  Return the count of a semaphore (because any integer is
 *		   possible, return of SYSERR may be ambiguous)
 *------------------------------------------------------------------------
 */
syscall cond_init(cond_t* cv)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();

	mutex_create(cv->qm);
	
	cv->front = 0;
	cv->rear = -1;
	
	// qid16 myqueue = newqueue();
	// cv->q = myqueue;

	// memcpy(&cv->q, myqueue);

	restore(mask);
	return 0;
}