#include <stdio.h>

// argc è il numero di argomenti passati al programma
// argv è un array di stringhe che contiene gli argomenti

// (più precisamente argv è un array di puntatori a char)

int main(int argc, char const *argv[])
{
    int i;
    // numero di argomenti: argc
    printf("There were %d arguments provided:\n", argc);
    for (i = 0; i < argc; i++)
    {
        // ciascuno argomento: argv[i] (il primo è il nome del programma)
        printf("Argument #%d\t-\t%s\n", i, argv[i]);
    }

    return 0;
}
