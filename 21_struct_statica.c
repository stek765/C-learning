// Con struttura STATICA si intende che la struttura viene passata per valore, 
// quindi viene creata una COPIA della struttura originale.

// SE HO UNA STRUTTURA STATICA, USO '.' PER ACCEDERE AI CAMPI (es: nome.num)
// ---------------------------------------------------------------

#include <stdio.h>
#define N 10

// Struttura semplice, senza puntatori
typedef struct {
    int num;
    char car; 
} struttura;

// Funzione che modifica una struct passata per valore
struttura funzioneStatica(struttura nome, int n) {
    nome.num = n;
    return nome; // restituisce la struct modificata
}

int main() {
    struttura StaticStruct;
    StaticStruct = funzioneStatica(StaticStruct, N);

    printf("\n[STATICA] La funzione ha impostato num = N:\n%d\n", StaticStruct.num);

    return 0;
}
