#include <stdio.h>

int main() {
    int i = 0;

    // Costrutto if
    if (i == 0) {
        printf("Costrutto if: i è uguale a 0\n");
    }

    // Costrutto for
    printf("Costrutto for: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Costrutto while
    printf("Costrutto while: ");
    while (i < 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    // Costrutto do-while
    printf("Costrutto do-while: ");
    do {
        printf("%d ", i);
        i--;
    } while (i > 0);
    printf("\n");

    return 0;
}
