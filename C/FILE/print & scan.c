#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    fprintf(stdout, "Hello World");
    printf("\nCiao!!\n\nInserisci una stringa:  ");

    char in[20];

    // Utilizzo di scanf per leggere una stringa dall'input
    scanf("%19s", in);
    printf("%25s", in);

    // Verifica del numero di argomenti passati da linea di comando
    // argc è il numero di elementi passati
    // Primo argomento: Nome del programma
    // Secondo in poi tutti quelli passati
    if (argc != 3) {
        perror("Numero di argomenti errato");
        exit(1);
    }
    
    //Per passarli da terminale: gcc nomefile.c   
    //                           ./a.out Harry Potter
    printf("\n\nargv[1] -> %s \nargv[2] -> %s", argv[1], argv[2]);

    return 0;
}
