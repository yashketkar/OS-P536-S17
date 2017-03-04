#ifndef _FUTURE_H_
#define _FUTURE_H_  

//http://www.learn-c.org/en/Linked_lists
typedef struct node{
    int val;
    struct node* next;
} node_t;

typedef enum {
  FUTURE_EMPTY,
  FUTURE_WAITING,
  FUTURE_READY
} future_state_t;

typedef enum {
  FUTURE_EXCLUSIVE,
  FUTURE_SHARED,
  FUTURE_QUEUE
} future_mode_t;

typedef struct {
  int value;
  future_state_t state;
  future_mode_t mode;
  pid32 pid;
  node_t* set_queue;
  node_t* get_queue;
} future_t;

/* Interface for the Futures system calls */
future_t* future_alloc(future_mode_t mode);
syscall future_free(future_t*);
syscall future_get(future_t*, int*);
syscall future_set(future_t*, int);

#endif /* _FUTURE_H_ */