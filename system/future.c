/* Interface for the Futures system calls */
// future_t* future_alloc(future_mode_t mode);
// syscall future_free(future_t* f);
// syscall future_get(future_t*, int*);
// syscall future_set(future_t*, int);

#include <xinu.h>

future_t* future_alloc(future_mode_t mode){
	future_t* new_future_t = getmem(sizeof(future_t));
	new_future_t->state = FUTURE_EMPTY;
	new_future_t->mode = mode;
	return new_future_t;
}

syscall future_free(future_t* f){
	int status = freemem(f, sizeof(future_t));
	if(status == 0){
		return OK;
	}
	return SYSERR;
}

syscall future_get(future_t* f, int* value){
	//TODO wait and obtain
	value = &(f->value);
	f->state = FUTURE_EMPTY;
	return 0; //TODO return SYSERR or OK
}

syscall future_set(future_t* f, int value){
	f->value = value;
	f->state = FUTURE_READY;
	return 0; //TODO return SYSERR or OK
}
