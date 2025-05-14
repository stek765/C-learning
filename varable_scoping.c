// Il Variable Scoping consiste nel definire la visibilità delle variabili.
// Questo attraverso l'uso di: parentesi graffe, funzioni e variabili globali.

#include <stdio.h>

// Variabile globale
int globale = 100;

void stampa() {
    int dentro_funzione = 200; // Visibile solo dentro questa funzione

    printf("[stampa] globale: %d\n", globale);
    printf("[stampa] dentro_funzione: %d\n", dentro_funzione);
}

int main() {
    int dentro_main = 50; // Visibile solo dentro main

    printf("[main] globale: %d\n", globale);
    printf("[main] dentro_main: %d\n", dentro_main);

    // Blocco interno nel main
    {
        int dentro_blocco = 75;       // Visibile solo dentro questo blocco
        int globale = 999;            // Maschera la globale solo qui

        printf("[blocco] dentro_blocco: %d\n", dentro_blocco);
        printf("[blocco] globale (mascherata): %d\n", globale);
    }

    // stampa("fuori blocco: %d\n", dentro_blocco); // Errore se decommenti

    stampa(); // Chiama funzione che ha le sue variabili

    return 0;
}

/*
📘 Riepilogo:
- Variabili GLOBALI: visibili ovunque (es: 'globale')
- Variabili LOCALI: visibili solo dentro la funzione o blocco dove sono dichiarate
- Una variabile con lo stesso nome "maschera" una variabile più esterna

- Variabili STATICHE: rende la variabile visibile solo in quel file
                      e mantiene il valore tra le chiamate (es: void fn{static int i = 0;}  )
*/


