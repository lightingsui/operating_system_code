//
// Created by sui on 2021/2/23.
//
#include "common.h"
#include "producer.h"
#include "consumer.h"

int main() {
    int producer_thread1_status = 0;
    int producer_thread2_status = 0;

    int customer_thread1_status = 0;
    int customer_thread2_status = 0;

    pthread_t producer_thread1 = 0;
    pthread_t producer_thread2 = 0;

    pthread_t customer_thread1 = 0;
    pthread_t customer_thread2 = 0;

    while (true) {
        producer_thread1_status = pthread_create(&producer_thread1, NULL, producer, NULL);
        customer_thread1_status = pthread_create(&customer_thread1, NULL, consumer, NULL);
        producer_thread2_status = pthread_create(&producer_thread2, NULL, producer, NULL);
        customer_thread2_status = pthread_create(&customer_thread2, NULL, consumer, NULL);
        printf("\n");
        sleep(2);
    }


    return 0;
}

