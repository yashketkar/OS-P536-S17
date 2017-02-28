/* Interface for the Futures system calls */
// future_t* future_alloc(future_mode_t mode);
// syscall future_free(future_t* f);
// syscall future_get(future_t*, int*);
// syscall future_set(future_t*, int);

#include <future.h>

future_t* future_alloc(future_mode_t mode){
	future_t* new_future_t;
	GetMem(new_future_t, sizeof(future_t));
	new_future_t->future_state_t = FUTURE_EMPTY;
	new_future_t->future_mode_t = mode;
	return new_future_t;
}

syscall future_free(future_t* f){
	int status = freemem(f);
	if(status == 0){
		return OK;
	}
	return SYSERR;
}

syscall future_get(future_t* f, int* value){
	//TODO wait and obtain
	value = &(f->value);
	f->future_state_t = FUTURE_EMPTY;
	return 0; //TODO return SYSERR or OK
}

syscall future_set(future_t* f, int value){
	f->value = value;
	f->future_state_t = FUTURE_VALID;
	return 0; //TODO return SYSERR or OK
}