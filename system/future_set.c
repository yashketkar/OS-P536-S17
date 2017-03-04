/* future_exclusive_set.c - future_exclusive_set */

#include <xinu.h>
#include <stdio.h>
#include <future.h>

/*
	syscall future_set(future_t* f, int value) - Set a value in a future and changes state from FUTURE_EMPTY or FUTURE_WAITING to FUTURE_VALID.
	Parameters:
	future_t* f - Future in which to set the value
	int value - Result of an operation to be set as value in the future
	Returns: syscall - SYSERR or OK
*/

static syscall future_exclusive_set(future_t* f, int* value) {
	if (f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING) {
		f->value = (int*)getmem(sizeof(int));
		*(f->value) = *value;
		f->state = FUTURE_READY;

		resume(f->pid);
		return OK;
	}
	return SYSERR;
}

static syscall future_shared_set(future_t* f, int* value) {
	f->value = (int*)getmem(sizeof(int));
	*(f->value) = *value;
	f->state = FUTURE_READY;

	QueueItem proc;

	while (queue_pop(f->get_queue, &proc)) {
		printf("Resuming process: %d\n", proc.value);
		resume(proc.value);
	}
	return OK;
}

static syscall future_queue_set(future_t* f, int* value) {
	f->value = (int*)getmem(sizeof(int));
	*(f->value) = *value;
	f->state = FUTURE_READY;

	QueueItem proc;
	if (queue_pop(f->get_queue, &proc)) {
		resume(proc.value);
	} else {
		pid32 pid = getpid();
		queue_push(f->set_queue, (QueueItem){pid});
		suspend(pid);
		if (queue_pop(f->get_queue, &proc)) {
			resume(proc.value);
		} else {
			return SYSERR;
		}
	}
	return OK;
}

syscall future_set(future_t* f, int* value) {
	if (f == NULL) {
		return SYSERR;
	}

	int mask = disable();

	if (f->state == FUTURE_READY) {
		restore(mask);
		return SYSERR;
	}

	syscall res = SYSERR;
	switch (f->mode) {
		case FUTURE_EXCLUSIVE:
			 res = future_exclusive_set(f, value);
			 break;
		case FUTURE_SHARED:
			 res = future_shared_set(f, value);
			 break;
		case FUTURE_QUEUE:
			 res = future_queue_set(f, value);
			 break;
	}
	restore(mask);
	return res;
}
