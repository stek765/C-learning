// L'implementazione ancora generica, del gioco di forza 4 con i 2 processi e il server
// che mette la matrice del gioco nella shared memory e i 2 processi poi vi accedono
// tutto prendendo il mutex e rilasciandolo e con l'aggiunta di un valore che rappresenta
// quale processo dovrà eseguire l'operazione nel mutex (così da alternarli).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int matrix[ROWS][COLS];
    int next_process; // 0 or 1 to indicate which process should access the data next
} SharedData;

int main() {
    int shmid;
    key_t key = 1234;
    SharedData *shared_data;

    // Create shared memory segment
    shmid = shmget(key, sizeof(SharedData), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment
    shared_data = (SharedData *)shmat(shmid, NULL, 0);
    if (shared_data == (SharedData *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize shared data (example)
    shared_data->next_process = 0;

    // Server writes data to shared memory and updates shared variable

    // Process reads shared variable and accesses data if it's their turn

    // Detach shared memory segment
    if (shmdt(shared_data) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}
