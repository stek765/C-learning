#include <stdio.h>

// Matrici tridimensionali hanno come primo parametro [] il numero di matriche che contengono
// in questo caso [2 matrici] di dim = 3 * 4

int main() {
    // Definizione e inizializzazione di un array tridimensionale 2x3x4
    int array_tridimensionale[2][3][4] = {
        {
            {11, 22, 33, 4},
            {5, 62, 73, 82},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    // Stampa l'array tridimensionale
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%d ", array_tridimensionale[i][j][k]);
            }
            printf("\n"); // Vai a capo dopo ogni riga di profondità
        }
        printf("\n"); // Vai a capo dopo ogni matrice
    }

    return 0;
}
