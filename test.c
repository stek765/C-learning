#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h> // Required for O_CREAT
#include <stdlib.h> // Required for exit

#define NUM_THREADS 5

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    sem_t *semaphore = sem_open("/my_semaphore", O_RDWR);
    
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    
    // Acquire semaphore
    if (sem_wait(semaphore) == -1) {
        perror("sem_wait");
        exit(EXIT_FAILURE);
    }
    
    // Critical section: accessing shared resource
    printf("Thread %d is accessing the shared resource.\n", thread_id);
    
    // Release semaphore
    if (sem_post(semaphore) == -1) {
        perror("sem_post");
        exit(EXIT_FAILURE);
    }
    
    // Close semaphore
    if (sem_close(semaphore) == -1) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    
    // Create semaphore
    sem_t *semaphore = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0644, 1);
    
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy semaphore
    if (sem_close(semaphore) == -1) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }
    
    if (sem_unlink("/my_semaphore") == -1) {
        perror("sem_unlink");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
