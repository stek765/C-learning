#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define n 10 // Define a constant for the size of the array

int main(int argc, char *argv[]) {
    
    int *arr1, *arr2;
    int lung_arr = 10; // Set a value for lung_arr
    
    srand(time(NULL));
    
    arr1 = calloc(lung_arr, sizeof(int));  // Allocate memory for arr1
    arr2 = malloc(lung_arr * sizeof(int)); // Allocate memory for arr2
    
    int *test = malloc(n * sizeof(int)); 
    int *test2 = malloc(sizeof(int));
    
    // Error excp
    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // CALLOC SETTA A ZERO LA MEMORIA ALLOCATA
    // MALLOC NO
    
    // stampa il contenuto degli array non assegnati ancora
    for (int i = 0; i < lung_arr; i++) {
        // 2 modi per fare la stessa cosa
        printf(" %d | ", *(arr1+i));
        printf(" %d \n", *(arr2+i)); 
    }
    /* - - - - - - - - - - - - - - - - - - - - - - */
    
    printf("\n\n\n");

    for (int i = 0; i < lung_arr; i++) {
    // 2 modi uguali per assegnare i valori
      *(arr1+i) = 10 + rand() % (77 - 10 + 1);
        arr2[i] = 10 + rand() % (77 - 10 + 1);
    }
    
    // stampa il contenuto degli array assegnati 
    for (int i = 0; i < lung_arr; i++) {
        // 2 modi per fare la stessa cosa
        printf(" %d | ", *(arr1+i));
        printf(" %d \n", arr2[i]); 
    }
    
    
    // Free allocated memory
    free(arr1);
    free(arr2);
    
}

