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

	node_t* next;
	while(f->set_queue){
		next = f->set_queue->next;
		freemem(f->set_queue, sizeof(node_t));
		f->set_queue = f->set_queue->next;
	}

	int status = freemem(f, sizeof(future_t));
	if(status == 1){
		return OK;
	}
	return SYSERR;
}

syscall future_get(future_t* f, int* value){
	//check for exclusive mode
	if(f->mode == FUTURE_EXCLUSIVE){
		if(f->state == FUTURE_READY){
			*value = f->value;
			f->state = FUTURE_EMPTY;
			return OK;
		}
	}
	else{
		while(1){
			if(f->state == FUTURE_READY){
				break;
			}
		}
		*value = f->value;
		f->state = FUTURE_EMPTY;
		return OK;
	}
	return OK;
}

syscall future_set(future_t* f, int value){
	f->value = value;
	f->state = FUTURE_READY;
	return OK;
}