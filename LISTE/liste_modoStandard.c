#include "list.h"
#include <stdlib.h>

//Si noti che ho importato list.h


/*
Questo modo rende il liste_modo2 MOLTO MIGLIORE e personalmente penso sia 
il più comodo da usare

la differenza tra questo e il secondo è che invece di avere:  typedef struct Nodo* List;   e poi List nuovoNodo = malloc..
													abbiamo:  typedef struct Nodo ELEMENT; typedef ELEMENT *List; e poi List nuovoNodo = malloc..
																						   (scritto con *LINK e poi LINK head)
												
Il motivo per cui list_modo2 non funziona è stupido, ovvero non puoi fare i 2 passaggi in uno, 
perchè altrimenti List non viene considerato puntatore. Quell'ELEMENT è pressochè inutile ma fondamentale per il passaggio corretto di tipo.
												
*/
												
void inserisciInCoda(LINK lista, int valore);
void inserisciInTesta(LINK lista, int valore);
void visualizza(LINK lista);
void rimuovi(LINK lista, int valore);

int main(int argc, char* argv[]){
	
	LINK head = malloc(sizeof(ELEMENT));
	
	srand(time(NULL));
	int new_value = 1 + rand()%(100 - 1 + 1);
	
	inserisciInCoda(head, new_value);
	inserisciInCoda(head, new_value);
	inserisciInCoda(head, 77);
	inserisciInTesta(head, new_value);
	visualizza(head);
	
	rimuovi(head, 77);
	visualizza(head);
	
	free(head);
}

// Inserisci in coda
void inserisciInCoda(LINK lista, int valore) {
	
	LINK tmp;
	LINK prec;
	
	tmp = malloc(sizeof(ELEMENT));
	if (tmp == NULL)
		printf("Error malloc tmp");
	
	tmp->dato = valore;
	tmp->next = NULL;
	
	if (lista == NULL)
		lista = tmp;
	else{
		for (prec = lista; prec->next != NULL; prec = prec->next);
		prec->next = tmp;
	}
}

// Inserisci in testa
void inserisciInTesta(LINK lista, int valore) {
	
	LINK tmp = malloc(sizeof(ELEMENT));
	tmp->dato = valore;
	tmp->next = lista;
	
	lista = tmp;
}

// Visualizza
void visualizza(LINK lista) {
	LINK tmp = lista;
	
	while (tmp != NULL) {
		printf("%d ", tmp->dato);
		tmp = tmp->next;
	}
}

// Rimuovi (solo 1 valore == valorre. Non tutte le ricorrenze)
void rimuovi(LINK lista, int valore) {
	LINK tmp;
	LINK prec;
	
	if ((lista)->dato == valore){
		tmp = lista;
		lista = (lista)->next;
	} else {
		prec = lista;
		tmp = (lista)->next;
		while (tmp != NULL && tmp->dato != valore){
			prec = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			printf("\nValore non trovato");
			return;
		}
		prec->next = tmp->next;
	}
	free(tmp);
	printf("\n\nNodo rimosso\n\n");
}
