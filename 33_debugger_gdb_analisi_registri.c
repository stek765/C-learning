/*
# GUIDA RAPIDA GDB PER DEBUG C E ISPEZIONE ASSEMBLY

# 1. Compilazione con maggiori debug info (-g):
gcc -g -o programma programma.c

# 2. Avviare GDB
gdb ./programma

# 3. Impostare breakpoint
break main                 # Break all'inizio del main
break funzione             # Break in una funzione specifica
break file.c:42            # Break a riga 42 di file.c

# 4. Avviare l'esecuzione
run                        # Esegui il programma fino al primo breakpoint

# 5. Avanzare nel codice
next                       # Prossima riga (senza entrare in funzioni)
step                       # Entra nelle funzioni chiamate
continue                   # Continua fino al prossimo break
finish                     # Termina la funzione corrente

# 6. Osservare variabili
print variabile            # Mostra valore di una variabile
print/x variabile          # Mostra valore in esadecimale

# 7. Vedere registri e assembly
i r                        # Mostra tutti i registri (i = info)
i r eax                    # Mostra solo eax
disassemble                # Disassembla funzione corrente
disassemble main           # Disassembla il main
layout asm                 # Modalità split Assembly + sorgente
layout regs                # Mostra i registri a lato (incluso RIP) (utile in TUI)

# 8. Navigazione tra C e Assembly
start                      # Avvia e si ferma alla prima riga di main
layout src                 # Torna alla visualizzazione sorgente C
layout split               # Mostra C e Assembly insieme (TUI mode)

# 9. Osservare memoria e stack
x/10x $rsp                 # Mostra 10 parole in esadecimale da RSP
x/20i $rip                 # Mostra 20 istruzioni da RIP (x = examine)


# 9.1 leggere dal registro EIP/RIP:
Anche se il registro si chiama EIP nei sistemi a 32 bit e RIP nei 64 bit, il concetto è identico:
i r rip                  # Mostra il valore attuale di RIP
x/i $rip                 # Mostra 1 istruzione all’indirizzo contenuto in RIP
x/5i $eip                # Per sistemi a 32 bit
x/5i $rip                # Per sistemi a 64 bit, Mostra 5 istruzioni partendo da RIP
x/10i $rip-10            # Mostra le 10 istruzioni precedenti (se possibile)

x/5i 0xindirizzo   # per vedere 5 istruzioni da un indirizzo preciso

# 10. Uscire da GDB
quit                       # Esci da GDB

# Suggerimento: attiva modalità TUI (testuale interattiva)
# Avvia con:
gdb -tui ./programma

*/

#include <stdio.h>

int somma(int a, int b) {
    int risultato = a + b;
    return risultato;
}

int main() {
    int x = 5;
    int y = 10;
    int z = somma(x, y);
    printf("La somma è: %d\n", z);
    return 0;
}

