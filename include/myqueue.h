#ifndef MYQUEUE_H
#define MYQUEUE_H

typedef struct MyQueue MyQueue;

typedef struct {
	int32 value;
} QueueItem;

MyQueue* queue_alloc(int);

int queue_pop(MyQueue*, QueueItem*);
int queue_push(MyQueue*, QueueItem);
int queue_size(MyQueue*);

void queue_walk(MyQueue*);

syscall queue_free(MyQueue*);

#endif
