//
// Created by sui on 2021/2/23.
//

#ifndef OPERATING_SYSTEM_QUEUE_H
#define OPERATING_SYSTEM_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define bool _Bool
#define true 1
#define false 0
#define MAX 20
int QUEUE[MAX];

int deQueue();

bool enQueue(int value);

bool empty();

bool full();

int size();

int tail;

#endif //OPERATING_SYSTEM_QUEUE_H



