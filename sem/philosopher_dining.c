//
// Created by sui on 2021/2/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define FORK_COUNT 5
#define LAST_PHILOSOPHER_ID 4

sem_t forks[FORK_COUNT];

void eat(int id);

int left_fork(int id) {
    return id;
}

int right_fork(int id) {
    return (id + 1) % FORK_COUNT;
}

void put_fork(int id) {
    sem_post(&forks[left_fork(id)]);
    sem_post(&forks[right_fork(id)]);
}

void get_fork(int id) {
    if (id == LAST_PHILOSOPHER_ID) {
        sem_wait(&forks[right_fork(id)]);
        sem_wait(&forks[left_fork(id)]);
    } else {
        sem_wait(&forks[left_fork(id)]);
        sem_wait(&forks[right_fork(id)]);
    }
}

void *dinner(void *args) {
    int id = *(int *) args;
    get_fork(id);
    eat(id);
    put_fork(id);
}

void eat(int id) {
    printf("philosopher id: %d is eating\n", id);
}

int main() {
    for (int i = 0; i < FORK_COUNT; ++i) {
        sem_init(&forks[i], 0, 1);
    }

    pthread_t philosopher1, philosopher2, philosopher3
    , philosopher4, philosopher5;

    int id1 = 0;
    int id2 = 1;
    int id3 = 2;
    int id4 = 3;
    int id5 = 4;

    pthread_create(&philosopher1, NULL, dinner, &id1);
    pthread_create(&philosopher2, NULL, dinner, &id2);
    pthread_create(&philosopher3, NULL, dinner, &id3);
    pthread_create(&philosopher4, NULL, dinner, &id4);
    pthread_create(&philosopher5, NULL, dinner, &id5);

    pthread_join(philosopher1, NULL);
    pthread_join(philosopher2, NULL);
    pthread_join(philosopher3, NULL);
    pthread_join(philosopher4, NULL);
    pthread_join(philosopher5, NULL);

    return 0;
}


