/* cond_init.c - cond_init */

#include <xinu.h>

syscall cond_init( cond_t* cv )
{
	intmask	mask;			/* Saved interrupt mask		*/
	
	mask = disable();
	
	//TODO
	//Create a condition variable and set its initial state.
	cv->val = 0;

	restore(mask);
	return cv->val;
}
