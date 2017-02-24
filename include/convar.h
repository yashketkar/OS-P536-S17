/* convar.h */

/* condition variable struct */

typedef struct {
    queent q;
    mutex_t lock;
} cond_t;

extern syscall cond_init(cond_t* cv);

extern syscall cond_wait(cond_t* cv, mutex_t* lock);

extern syscall cond_signal(cond_t* cv);