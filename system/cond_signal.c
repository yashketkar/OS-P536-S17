/* cond_signal.c - cond_signal */

#include <xinu.h>
#include <conditionvariable.h>

/*------------------------------------------------------------------------
 *  cond_signal  - Condition Variable Signal
 *------------------------------------------------------------------------
 */

syscall cond_signal(cond_t* cv)
{
	intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();

    pid32 mypid = -1024;

    mutex_lock(cv->qm); /* protect the queue */
    
    if(cv->front <= cv->rear){
        mypid = cv->queue[cv->front++];
    }
    
    mutex_unlock(cv->qm);
  
    if (mypid>0){
        resume(mypid);
    }

    restore(mask);
    return 0;
}