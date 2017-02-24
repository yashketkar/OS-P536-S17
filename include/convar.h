/* convar.h */

/* condition variable struct */

typedef struct {
    int32 val;
} cond_t;

extern syscall cond_init(cond_t* cv);

extern syscall cond_wait(cond_t* cv, mutex_t* lock);

extern syscall cond_signal(cond_t* cv);