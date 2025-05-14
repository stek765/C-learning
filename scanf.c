#include <stdio.h>
#include <string.h> // Per strcpy

int main(){
    char message[10];
    int count, i;

    strcpy(message, "Hello");  // metto Hello all'interno della stringa message

    printf("Enter how many times: ");
    scanf("%d", &count); // scanf richiede che gli si passi un'indirizzo

    for(i = 0; i < count; i++){
        printf("%3d - %s\n", i, message); // %3d per stampare un numero con 3 cifre
    }
}