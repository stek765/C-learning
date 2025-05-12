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