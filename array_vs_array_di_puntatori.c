// Differenza tra puntatore e array di puntatori:

#include <stdio.h>

int main() {
    // 1. Puntatore singolo a una stringa
    char *singolo = "Ciao";
    // 'singolo' contiene l'indirizzo del primo carattere della stringa "Ciao"
    //  La stringa è salvata in una zona di memoria costante (read-only)

    // 2. Array di 3 puntatori a stringa costante
    char *frasi[3] = {"Uno", "Due", "Tre"};
    // 'frasi' è un array (allocato nello stack) di 3 puntatori
    //  Ogni elemento frasi[i] è un char*, ovvero un indirizzo che punta alla prima lettera di una stringa costante

    // Stampa i valori e gli indirizzi per chiarire la differenza
    printf("[Puntatore singolo]\n");
    printf("singolo: %s\n", singolo);                            // Stampa la stringa "Ciao"
    printf("&singolo: %p\n", (void*)&singolo);                   // Indirizzo della variabile 'singolo' (dove è salvato il puntatore)
    printf("singolo (valore, indirizzo della stringa): %p\n", (void*)singolo); // Valore di 'singolo': puntatore alla stringa

    printf("\n[Array di puntatori]\n");
    for (int i = 0; i < 3; i++) {
        printf("frasi[%d]: %s\n", i, frasi[i]);                  // Stampa la stringa puntata da frasi[i]
        printf("&frasi[%d]: %p\n", i, (void*)&frasi[i]);         // Indirizzo nel tuo array (dove sta il puntatore)
        printf("frasi[%d] (valore, indirizzo della stringa): %p\n", i, (void*)frasi[i]); // Valore: indirizzo della stringa
        printf("frasi[%d][0] (primo carattere): %c\n\n", i, frasi[i][0]); // Dereferenziazione doppia: prendi il primo carattere della stringa
    }

    return 0;
}

/*
──────────────────────────────────────────────────────────────────────────────
📘 Spiegazione:

- char *singolo = "Ciao";
  → 'singolo' è un singolo puntatore a char, che punta alla stringa "Ciao"
  → '&singolo' è l'indirizzo di memoria dove è salvato il puntatore
  → 'singolo' è il valore: un indirizzo che punta alla stringa costante

- char *frasi[3] = {"Uno", "Due", "Tre"};
  → 'frasi' è un array di 3 puntatori a char (stack)
  → ogni 'frasi[i]' è un char* → punta alla stringa "Uno", "Due", "Tre"
  → '&frasi[i]' è l'indirizzo della cella frasi[i] dentro l'array (sul stack)

- Differenze:
    frasi[0]      → indirizzo della stringa "Uno"
    *frasi[0]     → 'U'
    &frasi[0]     → indirizzo della variabile frasi[0] (cella dell'array)
    frasi[0][0]   → primo carattere della stringa "Uno"

──────────────────────────────────────────────────────────────────────────────
💾 Disegno della memoria (semplificato)

// Stack
indirizzo       contenuto         significato
0xAAA0          0xDEADBEAF        ← questo è frasi[0], cioè il puntatore alla stringa "Uno"
0xDEADBEAF      'U', 'n', 'o'...  ← stringa "Uno" in memoria read-only

──────────────────────────────────────────────────────────────────────────────
📐 Struttura più completa:

Stack (array frasi):

  +-------------------+
  | frasi[0]          | ----+  → "Uno\0"
  +-------------------+     |
  | frasi[1]          | ----+--→ "Due\0"
  +-------------------+     |
  | frasi[2]          | ----+--→ "Tre\0"
  +-------------------+

Ogni 'frasi[i]' è un indirizzo che punto alla base di una stringa
Ogni '&frasi[i]' è l'indirizzo in memoria del puntatore stesso

──────────────────────────────────────────────────────────────────────────────

*/
