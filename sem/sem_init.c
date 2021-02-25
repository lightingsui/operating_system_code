//
// Created by sui on 2021/2/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef unsigned int u32;

u32 number = 0;
sem_t sem;

void *add_number(void *args) {
    sem_wait(&sem);
    number++;
    sem_post(&sem);
}

// 二值信号量（代替锁）
int main() {
    // @__sem： sem_t信号量的地址
    // @pshared: 为 0 时代表同一进程下的多个线程共享此信号量
    // @value: 代表信号量的初始值
    sem_init(&sem, 0, 1);

    pthread_t pthread1, pthread2;

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 100000; ++i) {
            pthread_create(&pthread1, NULL, add_number, NULL);
            pthread_create(&pthread2, NULL, add_number, NULL);

            pthread_join(pthread1, NULL);
            pthread_join(pthread2, NULL);
        }

        printf("number result: %d\n", number);
    }

    return 0;
}

