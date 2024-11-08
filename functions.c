#include "my_header.h"

int is_empty(queue_t *que) {
    if(que->head == NULL) {
        return 1;
    }
    return 0;
}
void constructor(queue_t *que) {
    que->head = NULL;
    pthread_mutex_init(&que->lock, NULL);
    return;
}

task_t my_pop(queue_t *que) {
    pthread_mutex_lock(&que->lock);
    if(que == NULL || que->head == NULL) {
        perror("error");
        pthread_mutex_unlock(&que->lock);
        exit(0);
    }else {
    node_t *tmp = que->head;
    task_t copy = tmp->task;
    que->head = que->head->next;
    free(tmp);
    pthread_mutex_unlock(&que->lock);
    return copy;
    }
}

void push_back(queue_t *que, task_t task) {
    if(que == NULL) {
        perror("queue is empty\n");
        exit(0);
    } 
    node_t *mid = (node_t*) malloc(sizeof(node_t));
    mid->next = NULL;
    mid->task = task; 
    if(que -> head == NULL) {
        que->head = mid;
    }else {
        node_t *tmp = que->head;
        while(tmp -> next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = mid;
    }
    return;
}