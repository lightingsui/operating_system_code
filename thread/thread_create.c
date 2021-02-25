//
// Created by sui on 2021/1/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* threadFunction(void* ptr) {
    int pid = getpid();

    printf("pid: %d", pid);
}

int main() {
    pthread_t pthread;
    int threadRes = -1;
    threadRes = pthread_create(&pthread, NULL, threadFunction, NULL);

    pthread_join(pthread, NULL);

    printf("thread create res: %d", threadRes);

    return 0;
}

