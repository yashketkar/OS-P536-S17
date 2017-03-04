/* future_get.c - future_get */

#include <xinu.h>
#include <future.h>

/*
	syscall future_get(future_t* f, int* value) - Get the value of a future set by an operation and change the state of future from FUTURE_VALID to FUTURE_EMPTY.
	Parameters:
	future_t* f - Future on which to wait for and obtain value
	int* value - Address into which the future's value will be copied.
	Returns: syscall - SYSERR or OK
*/

static syscall future_exclusive_get(future_t* f, int* value) {
	if (f->state == FUTURE_WAITING) {
		return SYSERR;
	}

	f->state = FUTURE_WAITING;
	f->pid = getpid();

	suspend(getpid());

	*value = *(f->value);
	f->state = FUTURE_EMPTY;
	f->pid = NULLPROC;
	return OK;
}

static syscall future_shared_get(future_t* f, int* value) {
	if (f->state == FUTURE_READY) {
		*value = *(f->value);
		return OK;
	} else {
		pid32 pid = getpid();
		if (!queue_push(f->get_queue, (QueueItem){pid})) {
			return SYSERR;
		}
		printf("Suspending process: %d\n", pid);
		suspend(pid);
		*value = *(f->value);
		return OK;
	}
}

static syscall future_queue_get(future_t* f, int* value) {
	if (f->state == FUTURE_READY) {
		*value = *(f->value);
		QueueItem proc;
		if (queue_pop(f->set_queue, &proc)) {
			f->state = FUTURE_EMPTY;
			resume(proc.value);
			return OK;
		}
		return SYSERR;
	}

	//otherwise, suspend current thread
	pid32 pid = getpid();
	if (!queue_push(f->get_queue, (QueueItem){pid})) {
		return SYSERR;
	}
	suspend(pid);
	*value = *(f->value);
	f->state = FUTURE_EMPTY;
	freemem(f->value, sizeof(int));
	return OK;
}

syscall future_get(future_t* f, int* value) {
	if (f == NULL) {
		return SYSERR;
	}

	int mask = disable();

	syscall res = SYSERR;
	switch(f->mode) {
		case FUTURE_EXCLUSIVE:
			res = future_exclusive_get(f, value);
			break;
		case FUTURE_SHARED:
			res = future_shared_get(f, value);
			break;
		case FUTURE_QUEUE:
			res = future_queue_get(f, value);
			break;
	}
	restore(mask);
	return res;
}
