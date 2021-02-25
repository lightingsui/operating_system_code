//
// Created by sui on 2021/2/23.
//
#include "common.h"
#include "queue.h"
#include "consumer.h"

void *consumer(void *args) {
    pthread_mutex_lock(&m_lock);

    // 处理逻辑
    while (empty()) {
        pthread_cond_wait(&cus, &m_lock);
    }

    int value = deQueue();
    printf("customer %u get value: %d\n", (u32_int) pthread_self(), value);

    if (empty()) {
        pthread_cond_signal(&pro);
    }

    pthread_mutex_unlock(&m_lock);
}

