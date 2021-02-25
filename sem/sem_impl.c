//
// Created by sui on 2021/2/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct _Sem_t {
    pthread_cond_t cond;
    pthread_mutex_t lock;
    int value;
} Sem_t;

void Sem_init(Sem_t *sem, int pshared, int value) {
    sem->value = value;
    pthread_cond_init(&sem->cond, NULL);
}

void Sem_wait(Sem_t *sem) {
    pthread_mutex_lock(&sem->lock);

    while (sem->value <= 0) {
        pthread_cond_wait(&sem->cond, &sem->lock);
    }

    sem->value--;
    pthread_mutex_unlock(&sem->lock);
}

void Sem_post(Sem_t *sem) {
    pthread_mutex_lock(&sem->lock);
    sem->value++;

    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->lock);
}

