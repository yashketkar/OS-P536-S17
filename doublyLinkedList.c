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

struct node *head;
struct node *tail;

void createHeadTail(){
    head->key = INT_MAX;
    head->process_id = 110; //assumption
    tail->process_id = 111; //assumption
    tail->key = INT_MIN;
}

//return next of head
struct node getFirst(){
    return *head->next;
}

int getFirstID(){
    return head->next->process_id;
}

//return prev of tail
struct node getLast(){
    return *tail->prev;
}

int getLastID(){
    return tail->prev->process_id;
}

bool isEmpty(){
    //get the first node's ID with getFirstID
    int first = getFirstID();
    return first >= NPROC;
}

bool nonEmpty(){
    //get the first node's ID with getFirstID
    int first = getFirstID();
    return first < NPROC;
}

int getFirstKey(){
    return head->next->key;
}

int getLastKey(){
    return tail->prev->key;
}

//FIFO manipulations

struct node enqueue(int processID){
    struct node *prev = tail->prev;

    //insert before tail
    struct node *newproc = (struct node*) malloc(sizeof(struct node));
    newproc->process_id = processID;
    newproc->next = tail;
    newproc->prev = prev;
    prev->next = newproc;
    tail->prev = newproc;

    return *newproc;
}

int dequeue(){
    struct node *target;
    int pid;
    if(isEmpty()){
        return EMPTY;
    }
    *target = getFirst();
    pid = target->process_id;
    target->prev = NULL;
    target->next = NULL;
    return pid;
}

//Priority Queue Manipulations
int insert(int processID, int key){
    struct node *curr;
    struct node *prev;

    if(isBadProcessID(processID)){
        return ERROR;
    }

    *curr = getFirst();
    while(curr->key >= key){
        curr = curr->next;
    }

    struct node *newproc = (struct node*) malloc(sizeof(struct node));
    newproc->process_id = processID;

    //insert process
    prev = curr->prev;
    newproc->next = curr;
    newproc->prev = prev;
    newproc->key = key;
    prev->next = newproc;
    curr->prev = newproc;

    return OK;
}

int main(){
    return 0;
}
