#ifndef P
#define P
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef void*(*job)(void*);
typedef struct{
    job current_job;
    void* arg;
} task_t;
typedef struct node_t{
    task_t task;
    struct node_t* next;
} node_t;
typedef struct{
    node_t* head;
    pthread_mutex_t lock;
} queue_t;
task_t my_pop(queue_t *que);
void constructor(queue_t *que);
int is_empty(queue_t *que);
void push_back(queue_t *que, task_t task);
#endif
