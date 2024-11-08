#include "my_header.h"
queue_t que;

void *foo(void*arg) {
    int a = *(int*)arg;
    printf("%d\n", a);
    return NULL;
} 

void *lib(void*arg) {
    printf("hello_world\n");
    return NULL;
}

void *bar(void*arg) {
    printf("good bye\n");
    return NULL;
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread(void *arg) {
    while(!is_empty(&que)) {
        task_t task = my_pop(&que);
        task.current_job(task.arg);
        // sleep(1);
    }
    return NULL;
}

int main() {
    constructor(&que);
    int a = 5;
    task_t task1 = {foo, &a};
    task_t task2 = {bar, NULL};
    task_t task3 = {lib, NULL};
    a = 10;
    task_t task4 = {foo, &a};
    push_back(&que, task1);
    push_back(&que, task2);
    push_back(&que, task3);
    push_back(&que, task4);
    push_back(&que, task4);
    push_back(&que, task1);
    push_back(&que, task2);
    push_back(&que, task3);
    push_back(&que, task4);
    push_back(&que, task4);
    pthread_t tid[4];
    for(int i = 0; i < 4; ++i) {
        pthread_create(&tid[i], NULL, thread, NULL);
    }
    for(int i = 0; i < 4; ++i) {
        pthread_join(tid[i], NULL);
    }

}