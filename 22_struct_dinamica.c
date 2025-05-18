// Con struttura DINAMICA si intende che la struttura viene passata per puntatore,
// quindi NON viene creata una COPIA della struttura originale.

// SE HO UN PUNTATORE A STRUTTURA, USO '->' PER ACCEDERE AI CAMPI (es: nome->num)
// ---------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#define N 10

// Struttura con puntatore ad un'altra struct
typedef struct anotherOne {
    char* stringhetta;
} anotherOne;

typedef struct {
    int num;
    char car;
    anotherOne *jump;
} struttura;

// Funzione che modifica una struct passata per puntatore
void funzioneDinamica(struttura* nome) {
    nome->num = N + 3;
    nome->jump->stringhetta = "BELLA BROTHER";
}

int main() {
    struttura *DinamicStruct = malloc(sizeof(struttura));
    if (DinamicStruct == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(EXIT_FAILURE);
    }

    DinamicStruct->jump = malloc(sizeof(anotherOne));
    if (DinamicStruct->jump == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(EXIT_FAILURE);
    }

    funzioneDinamica(DinamicStruct);

    printf("\n[Dinamica] La funzione ha impostato num = N+3:\n%d\n", DinamicStruct->num);
    printf("stringhetta -> %s\n", DinamicStruct->jump->stringhetta);

    // Libero la memoria
    free(DinamicStruct->jump);
    free(DinamicStruct);

    return 0;
}