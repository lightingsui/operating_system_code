//
// Created by sui on 2021/2/23.
//
#include "queue.h"

bool empty() {
    if (tail == 0) {
        return true;
    } else {
        return false;
    }
}

bool full() {
    if (tail == MAX) {
        return true;
    } else {
        return false;
    }
}

int deQueue() {
    int i = 1;
    if (empty()) {
        return -1;
    }

    int value = QUEUE[0];
    for (; i <= tail; i++) {
        QUEUE[i - 1] = QUEUE[i];
    }

    tail -= 1;

    return value;
}

bool enQueue(int value) {
    if (full()) {
        return false;
    }

    QUEUE[tail++] = value;
    return true;
}

int size() {
    return tail;
}

