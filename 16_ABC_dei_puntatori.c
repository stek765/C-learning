#include <stdio.h>

int main() {
    int int_var = 5;    // valore normale
    int *int_ptr;       // puntatore a intero

    int_ptr = &int_var; // puntatore che punta a int_var, ovver prende il suo indirizzo

    // Stampa i valori e gli indirizzi
    printf("int_ptr = 0x%08x\n", int_ptr);
    printf("&int_ptr = 0x%08x\n", &int_ptr);
    printf("*int_ptr = %d\n", *int_ptr);

    
    printf("int_var is located at 0x%08x and contains %d\n", &int_var, int_var);
    printf("int_ptr is located at 0x%08x, contains 0x%08x, and points to %d\n",
            &int_ptr, int_ptr, *int_ptr);
}