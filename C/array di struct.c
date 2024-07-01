#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Creo struct pro
typedef struct{
	int num;
	char car;
} tipo;


int main(int argc, char *argv[]) {
	
	//Facendo così ho creato un array di 10 elementi, in cui ciascun elemento è una struttura.
	tipo array[10];
	int k=0;
	
	srand(time(NULL));
	
	//Semplicemente qui stampo dei caratteri generati random
	//e li asseggno a tutti i 10 elementi dell'array nella sezione char car della loro struttura.
	// es: array[1].car = 'A'
	//RICORDO, che gli elementi dell'array sono tutte struct per conto loro
	
	while(k < 10){
		printf("\n%c", array[k++].car = 'A' + (rand() % 26));
	}
}