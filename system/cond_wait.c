/* cond_wait.c - cond_wait */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  cond_wait  -  Condition Variable Wait
 *------------------------------------------------------------------------
 */
syscall cond_wait(cond_t* cv, mutex_t* mutex)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();

    mutex_lock(cv->qm);  /* protect the queue */
    pid32 mypid = getpid();
    cv->queue[++cv->rear] = mypid;
    mutex_unlock(cv->qm); /* we're done with the list */
  
    mutex_unlock(mutex);
    suspend(mypid);
    mutex_lock(mutex);
    
    restore(mask);
    return 0;
}