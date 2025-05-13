#include <stdio.h>

int main() {
    // Array di char con terminatore '\0'
    char str[] = {'H', 'i', '\0'};

    // Puntatore a stringa (con terminatore implicito)
    const char *p = "Hi";

    // Mostra il terminatore come numero (perchè '\0' è 0 in ASCII)
    printf("str[2] = %d\n", str[2]);  // Stampa 0
    printf("p[2] = %d\n", p[2]);      // Stampa 0

    // Verifica se è uguale a zero
    if (str[2] == 0) printf("Termine array: '\\0' è 0\n");
    if (p[2] == 0)   printf("Termine puntatore: '\\0' è 0\n");

    return 0;
}