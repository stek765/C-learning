#include <stdio.h>
#include <stdlib.h>

#define N questo_è_esempiostruttura
#define M pointer_alla_esempiostruttura

struct esempiostruttura{
	char* nome;
	char* cognome;
	int eta;
};

int main(int argc, char *argv[]) {
	
	// Creo dei nuovi TIPI (intero, esempio, verastruttura)
	typedef int intero;
	typedef struct esempiostruttura  esempio;
	typedef struct esempiostruttura* verastruttura;

	
	intero n = 2;
	printf("\nintero: %d\n- - - - -\nstruttura:", n);
	
	esempio questo_è_esempiostruttura;
	// N = questo_è_esempiostruttura (define)
	N.nome = "Mario";
	N.cognome = "Rossi";
	N.eta = 30;
	printf("\n\nNome: %s\nCognome: %s\nEtà: %d\n", N.nome, N.cognome, N.eta);
	
	printf("\n- - - - - - - - - - -\n%s\n%s\n- - - - - - - - - - -", 

		"Ora modifico la struct tramite la nuova variabile-> verastruttura",
		"che ha tipo-> esempiostruttura*");
					
	verastruttura pointer_alla_esempiostruttura = malloc(sizeof(verastruttura));
	// M = pointer_alla_esempiostruttura (define)
	M->nome = "Luca";
	M->cognome = "Bianchi";
	M->eta = 25;
	printf("\n\nNome: %s\nCognome: %s\nEtà: %d\n", M->nome, M->cognome, M->eta);
	
}	
