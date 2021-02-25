//
// Created by sui on 2021/2/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem;

void* child(void* args) {
    printf("child begin\n");
    sem_post(&sem);
    printf("child end\n");
}


// 信号量用作条件变量
int main() {
    sem_init(&sem, 0, 0);
    pthread_t pthread;

    pthread_create(&pthread, NULL, child, NULL);

    sem_wait(&sem);

    printf("parent run\n");

    return 0;
}
