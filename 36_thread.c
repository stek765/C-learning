// This program demonstrates the use of POSIX threads (pthreads) in C.
// It creates multiple threads that perform busy work and then joins them.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

void *BusyWork(void *null) {
    int i;
    double result = 0.0;
    for (i = 0; i < 100000; i++) {
        result = result / 2 + (double)random();
    }
    printf("Thread result = %f\n", result);
    pthread_exit((void *) 0);
}

int main() {
    pthread_t thread[NUM_THREADS];
    pthread_attr_t attr;
    int rc, t, status;

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    // Set the thread to be joinable, which means the main thread has to wait for it to finish
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&thread[t], &attr, BusyWork, NULL);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Free attribute and wait for the other threads */
    pthread_attr_destroy(&attr);
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(thread[t], (void **)&status);
        if (rc) {
            printf("ERROR return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Completed join with thread %d status=%d\n", t, status);
    }

    pthread_exit(NULL);
}
