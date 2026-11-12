#include <pthread.h>
#include <stdio.h>

volatile int counter = 0;  // Global counter
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;  // Guards counter

void* incrementCounter(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&counter_lock);
        counter++;  // Increment under the lock
        pthread_mutex_unlock(&counter_lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads that increment the counter
    pthread_create(&thread1, NULL, incrementCounter, NULL);
    pthread_create(&thread2, NULL, incrementCounter, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of counter
    printf("Final counter value: %d\n", counter);
    return 0;
}
