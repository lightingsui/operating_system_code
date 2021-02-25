//
// Created by sui on 2021/2/23.
//
#include "common.h"

int enqueue_number = 0;
pthread_mutex_t m_lock;
pthread_cond_t cus;
pthread_cond_t pro;

void lock_init() {
    pthread_mutex_lock(&m_lock);
}

