/* cond_init.c - cond_init */

#include <xinu.h>

syscall cond_init( cond_t* cv )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Create a condition variable and set its initial state.
	cv->q->queinit();
	mutex_lock(cv->lock);

	restore(mask);
	return 0;
}
