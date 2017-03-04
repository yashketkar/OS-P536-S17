/* future_alloc.c - future_alloc */

#include <xinu.h>
#include <future.h>

/*
future_t* future_alloc(future_mode_t mode) - Allocates a new future (in the FUTURE_EMPTY state) with the given mode. We will use the getmem() call to allocate space to new future.
Parameters:
future_mode_t mode - The mode this future will operate in
Returns: future_t - NULL or a pointer to a valid future
*/

future_t* future_alloc(future_mode_t mode) {
	char* mem = getmem(sizeof(future_t));

	if (mem == SYSERR) {
		return SYSERR;
	}

	future_t *fut = (future_t*)mem;

	fut->value = NULL;
	fut->state = FUTURE_EMPTY;
	fut->mode = mode;
	fut->pid = NULLPROC;
	fut->set_queue = queue_alloc(15);
	fut->get_queue = queue_alloc(15);

	return fut;
}
