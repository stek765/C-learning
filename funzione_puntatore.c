#include <stdio.h>


void saluta() {
    printf("Ciao socio!\n");
}

void addio() {
    printf("Addio socio!\n");
}

int main() {
    // 🧠 Dichiarazione di un function pointer
    void (*fun_ptr)();

    // 🟢 Assegno la funzione 'saluta' al puntatore
    fun_ptr = saluta;

    // Chiamata diretta alla funzione
    saluta();  // Output: Ciao socio!

    // Chiamata indiretta tramite function pointer
    fun_ptr(); // Output: Ciao socio!

// - - - - - - - - - - - - -
    // Qui si vede il vantaggio del puntatore, ovvero
    // la possibilità di cambiare la funzione a runtime:

    // Cambio funzione puntata
    fun_ptr = addio;
    fun_ptr(); // Output: Addio socio!

    return 0;
}

/*
COSA SUCCEDE:
- saluta() è una chiamata diretta alla funzione
- fun_ptr() è una chiamata indiretta tramite puntatore
- entrambi eseguono la funzione, ma il puntatore permette di cambiare funzione a runtime (quando il prog è in esecuzione)
*/


// - - - - - - - - - - - - - -
// ESEMPIO CONCRETO E PIU' COMPLESSO:
#include <stdio.h>

int somma(int a, int b)    { return a + b; }
int sottrai(int a, int b)  { return a - b; }

int main() {
    // Array di function pointer
    int (*operazioni[])(int, int) = {somma, sottrai}; // un array di puntatori a funzioni con due parametri int

    int scelta;
    printf("0 = somma, 1 = sottrai: ");
    scanf("%d", &scelta);

    if (scelta >= 0 && scelta < 2) {
        int risultato = operazioni[scelta](5, 3); // chiamata dinamica
        printf("Risultato: %d\n", risultato);
    } else {
        printf("Scelta non valida\n");
    }

    return 0;
}