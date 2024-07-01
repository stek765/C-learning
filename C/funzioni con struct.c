	#include <stdio.h>
#include <stdlib.h>
#define N 10


/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */
//struct di tipo struttura
typedef struct{
	int num;
	char car;
	struct anotherOne *jump; //variabile che punta alla struttura anotherOne
} struttura;

//altra struttura con una variabile c
struct anotherOne{
	char* stringhetta;
}c;

/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */

//Dichiarazione funzioni
struttura funzioneStatica (struttura nome, int n);
void      funzioneDinamica (struttura* nome);
/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */


int main(int argc, char *argv[]) {
	//Creo le 2 variabili + l'allocazione di memoria di jump
	struttura StaticStruct;
	struttura* DinamicStruct = malloc(sizeof(struttura));
	//Controlli
	if (DinamicStruct == NULL) {
		printf("Errore di allocazione della memoria");
		exit(EXIT_FAILURE);
	}
	DinamicStruct->jump = malloc(sizeof(struct anotherOne));
	//Controlli
	if (DinamicStruct->jump == NULL) {
		printf("Errore di allocazione della memoria");
		exit(EXIT_FAILURE);
	}
		
	/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */
	StaticStruct = funzioneStatica(StaticStruct, N);
	printf("\nLa funzione statica mette il valore num = N: \n%d\n", StaticStruct.num);
	
	printf("- - - - - - - - - - -");
	
	funzioneDinamica(DinamicStruct);
	printf("\nLa funzione dinamica mette il valore num = N+3: \n%d\n", DinamicStruct->num);
	printf("\n%s\n%s\n\n%s%s\n",
			"Inoltre ho inserito una stringa all'interno di un altra struct",
			"di tipo anotherOne nella variabile stringhetta",
			"stringhetta -> ", DinamicStruct->jump->stringhetta); //potevo anche scrivere c.stringhetta
		
	free(DinamicStruct);
}

/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */
struttura funzioneStatica (struttura nome, int n){
	nome.num = n;
	return nome;
}

void funzioneDinamica (struttura* nome){
	nome->num = N+3;
	nome->jump->stringhetta = "BELLA BROTHER";
}