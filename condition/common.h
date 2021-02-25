//
// Created by sui on 2021/2/23.
//

#ifndef OPERATING_SYSTEM_COMMON_H
#define OPERATING_SYSTEM_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "queue.h"

typedef unsigned int u32_int;

extern pthread_mutex_t m_lock;
extern pthread_cond_t cus;
extern pthread_cond_t pro;

extern int enqueue_number;

void lock_init();

#endif //OPERATING_SYSTEM_COMMON_H
