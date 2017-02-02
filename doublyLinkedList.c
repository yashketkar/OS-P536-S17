#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
//assumptions
#define NQENT 104
#define NPROC 100
#define EMPTY (-1)
#define ERROR (-2)
#define OK (1000)
#define isBadProcessID(x) ( (int)(x) < 0 || (int)(x) >= NQENT-1 )

//node struct
struct node{
    int process_id;
    int key;

    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
//head = malloc(sizeof(struct node));
//head->process_id = 110;
//head->key = INT_MAX;

struct node *tail = NULL;

//create tail
struct node *tail = (struct node*) malloc(sizeof(struct node));
tail->process_id = 111; //assumption
tail->key = INT_MIN;

//return next of head
struct *node getFirst(){
    return head.next;
}

int getFirstID(){
    return queuetab[head.process_id].next.process_id;
}

//return prev of tail
struct *node getLast(){
    return tail.prev;
}

int getLastID(){
    return queuetab[tail.process_id].prev.process_id;
}

bool isEmpty(){
    //struct node *first = getFirstID();
    //return first.process_id >= NPROC;

    //get the first node's ID with getFirstID
    int first = getFirstID();
    return first >= NPROC;
}

bool nonEmpty(){
    //struct node *first = getFirstID();
    //return first.process_id < NPROC;

    //get the first node's ID with getFirstID
    int first = getFirstID();
    return first < NPROC;
}

int getFirstKey(){
    //get the first node with getFirst
    struct node *first = getFirst();
    return first.key;
}

int getLastKey(){
    //get the last node with getLast
    struct node *last = getLast();
    return last.key;
}

//FIFO manipulations

struct *node enqueue(int processID){
    struct node *prev = tail.prev;

    //insert before tail
    struct node *newproc = (struct node*) malloc(sizeof(struct node));
    newproc.process_id = processID;
    newproc.next = tail;
    newproc.prev = prev;
    prev.next = newproc;
    tail.prev = newproc;

    return newproc;
}

int dequeue(){
    struct node *target;
    int pid;
    if(isEmpty()){
        return EMPTY;
    }
    *target = getFirst();
    pid = target.process_id;
    target.prev = NULL;
    target.next = NULL;
    return pid;
}

//Priority Queue Manipulations
int insert(int processID, int key){
    struct node *curr;
    struct node *prev;

    if(isBadProcessID(processID)){
        return ERROR;
    }

    curr = getFirst();
    while(curr.key >= key){
        curr = curr.next;
    }

    struct node *newproc = (struct node*) malloc(sizeof(struct node));
    newproc.process_id = processID;

    //insert process
    prev = curr.prev;
    newproc.next = curr;
    newproc.prev = prev;
    newproc.key = key;
    prev.next = newproc;
    curr.prev = newproc;

    return OK;
}
