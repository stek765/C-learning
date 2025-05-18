#include <stdio.h>

int main() {
    // Dichiarazione e Assegnazione di variabili con lo stesso valore.
    int intero           = 10;
    unsigned int uint    = 10;
    short piccolo        = -5;
    long lungo           = 1000000;
    float decimale       = 10.5;
    double piu_preciso   = 3.1415926535;
    char carattere       = 'A';
    char stringa[]       = "Ciao";
    void *puntatore      = &intero;

    // Stampa dei valori delle variabili
    printf("Valore intero:         %d\n", intero);         // %d per int
    printf("Valore unsigned int:   %u\n", uint);           // %u per unsigned int
    printf("Valore short:          %hd\n", piccolo);        // %hd per short
    printf("Valore long:           %ld\n", lungo);          // %ld per long
    printf("Valore float:          %.2f\n", decimale);      // %.2f per float con 2 decimali
    printf("Valore double:         %.5lf\n", piu_preciso);   // %lf per double
    printf("Valore carattere:      %c\n", carattere);       // %c per char
    printf("Valore stringa:        %s\n", stringa);         // %s per stringhe (char *)
    printf("Indirizzo (puntatore): %p\n", puntatore);      // %p per stampare indirizzi (void *)

    // Typecasting esplicito
    float f = (float)intero; // Converte int in float
    int   i = (int)decimale; // Troncamento: 10.5 → 10

    printf("\nTypecasting:\n");
    printf("intero (int):     %d → float: %.1f\n", intero, f);
    printf("decimale (float): %.2f → int: %d\n", decimale, i);

    return 0;
}

/*
Formato stampa (specifier):
  %d   → int
  %u   → unsigned int
  %hd  → short
  %ld  → long
  %f   → float
  %lf  → double
  %c   → char
  %s   → stringa (char *)
  %p   → puntatore (void *)
*/

