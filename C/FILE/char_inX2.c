#include <stdio.h>
#include <signal.h>


volatile sig_atomic_t stop = 0;

/* il file va eseguito in uno dei seguenti modi:

   gcc -o nome nome.c
   1) ./nome
   2) ./nome < infile
   3) ./nome > outfile
   4) ./nome < infile > outfile   */

void sigint_handler(int signum) {
    stop = 1;
}

int main(void) {
    char c;
    
    
    // gestisce il segnale di Ctrl+C da terminale
    signal(SIGINT, sigint_handler);
    
    //prende una char e lo raddoppia
    while (!stop && scanf("%c", &c) == 1) {
        printf("%c", c);
        printf("%c", c);
    }
    
    if (feof(stdin)) {
        // End of file reached, input stream closed
        printf("\nEnd of input.\n");
    } else if (ferror(stdin)) {
        // Error occurred while reading from input stream
        perror("Error reading input");
    }
    
    return 0;
}
