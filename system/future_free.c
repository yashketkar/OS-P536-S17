/* future_free.c - future_free */

#include <xinu.h>
#include <future.h>

 /*
 	syscall future_free(future_t* f) - Frees the allocated future. Use the freemem() system call to free the space.
	Parameters:
	future_t* f - future to free
	Returns: syscall - SYSERR or OK
*/

syscall future_free(future_t* f) {
	if (f == NULL) {
		return SYSERR;
	}
	MyQueue* q1 = f->set_queue;
	MyQueue* q2 = f->get_queue;

	syscall v1 = queue_free(q1);
	syscall v2 = queue_free(q2);
	syscall v3 = OK;
	if (f->value) {
		v3 = freemem(f->value, sizeof(int));
		f->value = NULL;
	}
	syscall v4 = freemem((char*)f, sizeof(future_t));

	return v1 == SYSERR || v2 ==SYSERR || v3 ==SYSERR
		|| v4 == SYSERR? SYSERR: OK;
}
