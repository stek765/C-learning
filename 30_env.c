#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char* env[]) {
    int i;
    
    //Primo modo:
    printf("%s%s\n%s%s\n%s%s\n%s%s\n",
        "          Name: ",   getenv("NAME"),
        "          User: ",   getenv("USER"),
        "         Shell: ",   getenv("SHELL"),
        "Home directory: ",   getenv("HOME")); 
    
    printf("\n - - - - - \n\n     ||\n     VV\n");
    sleep(3);
    
    //Printa l'environment, l'ambiente
        for (i = 0; env[i] != NULL; ++i) {
        printf("--> %s\n", env[i]);
    }
    return 0;}