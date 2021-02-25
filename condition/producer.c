//
// Created by sui on 2021/2/23.
//

#include "producer.h"

void *producer(void *args) {
    pthread_mutex_lock(&m_lock);

    // 处理逻辑
    while (full()) {
        pthread_cond_wait(&pro, &m_lock);
    }

    int number = ++enqueue_number;
    enQueue(number);

    printf("producer %u create %d\n", (u32_int) pthread_self(), number);

    pthread_cond_signal(&cus);

    pthread_mutex_unlock(&m_lock);
}