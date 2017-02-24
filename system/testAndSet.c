/* testAndSet.c - testAndSet */

//Ref: https://en.wikipedia.org/wiki/Test-and-set

#define LOCKED TRUE
#include <xinu.h>

bool	testAndSet(
	  mutex_t* lock //lock
	)
{
	bool oldValue;
     
    oldValue = lock->hold;
    lock->hold = LOCKED;

    return oldValue;
}
