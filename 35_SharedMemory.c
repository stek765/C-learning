// gcc program_name.c -o program_name -lc

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key = 1234;
    char *shmaddr;

    // Creazione della memoria condivisa
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach della memoria condivisa
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Creazione del semaforo
    sem_t *sem;
    sem = sem_open("/my_semaphore", O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della memoria condivisa
    sprintf(shmaddr, "%d", 0);

    // Fork di un processo figlio
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processo figlio: incrementa la variabile condivisa
        sem_wait(sem); // Acquisizione del semaforo
        int val = atoi(shmaddr);
        val++;
        sprintf(shmaddr, "%d", val);
        sem_post(sem); // Rilascio del semaforo
        exit(EXIT_SUCCESS);
    } else {
        // Processo padre: stampa il valore della variabile condivisa
        wait(NULL);
        printf("Valore della variabile condivisa: %s\n", shmaddr);
    }

    // Rilascio delle risorse
    shmdt(shmaddr); // Detach della memoria condivisa
    shmctl(shmid, IPC_RMID, NULL); // Rimozione della memoria condivisa
    sem_close(sem); // Chiusura del semaforo
    sem_unlink("/my_semaphore"); // Rimozione del semaforo
    return 0;
}
