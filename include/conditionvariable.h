#include <xinu.h>
#define LOCKED 1

struct mutex_t
{
	volatile int lock;
};

typedef struct mutex_t mutex_t;

struct cond_t
{
	mutex_t* qm;
    pid32 queue[1024];
    int front;
    int rear;
};

typedef struct cond_t cond_t;