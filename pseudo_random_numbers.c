#include <stdio.h>
#include <stdlib.h> // per malloc, random, atoi, etc..

int main() {
    int i;
    print("RAND_MAX is %u\n", RAND_MAX);
    srand(time(0)); // inizializza il generatore di numeri casuali

    printf("random values from 0 to RAND_MAX:\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", rand());
    }
    printf("\n\nrandom values from 1 to 20:\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", rand() % 20 + 1);
    }
}