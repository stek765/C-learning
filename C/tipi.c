#include <stdio.h>

int main() {
    // Dichiarazione e Assegnazione di variabili con lo stesso valore.
    int intero     = 10;
    float decimale = 10.5;
    char carattere = 'A';
    
    // Stampa dei valori delle variabili
    printf("Valore intero:     %d\n", intero);
    printf("Valore decimale:   %.2f\n", decimale); // %.2f imposta la precisione a 2 decimali
    printf("Valore carattere:  %c\n", carattere);
    
    return 0;
}
