/* mutex.h */

/* mutex struct */

typedef struct {
    bool hold;
} mutex_t;

extern syscall mutex_create(mutex_t* lock);

extern syscall mutex_lock(mutex_t* lock);

extern syscall mutex_unlock(mutex_t* lock);