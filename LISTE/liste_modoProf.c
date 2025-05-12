#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Nodo {
    int dato;
    struct Nodo* prossimo;
};

typedef struct Nodo List;


void inserisciInCoda(List* lista, int valore);
void inserisciInTesta(List* lista, int valore);
void visualizza(List* lista);
void rimuovi(List* lista, int valore);


int main(int argc, char* argv[]){
    
    List* nuovoNodo = malloc(sizeof(struct Nodo));
    if(nuovoNodo == NULL) {
        printf("Errore nell'allocazione della memoria"); 
        return -1;
    }
    
    srand(time(NULL));
    
    int new_value = 10 + rand() % (90 - 10 + 1);
    printf("\n%d\n-----\n", new_value);
    
    inserisciInCoda(nuovoNodo, new_value);
    inserisciInCoda(nuovoNodo, new_value);
    inserisciInCoda(nuovoNodo, 77);
    inserisciInTesta(nuovoNodo, new_value);
    visualizza(nuovoNodo);
    
    printf("\n\n-----\n");
    
    rimuovi(nuovoNodo, 77);
    visualizza(nuovoNodo);
    
    free(nuovoNodo);
}

// Inserisci in coda
void inserisciInCoda(List* lista, int valore) {
    
    List* tmp;
    List* prec;
    
    tmp = malloc(sizeof(struct Nodo));
    if (tmp == NULL) {
        printf("Errore nell'allocazione della memoria");
        return;
    }
    
    tmp->dato = valore;
    tmp->prossimo = NULL;
    
    if (lista == NULL)
        lista = tmp;
    else{
        for (prec = lista; prec->prossimo != NULL; prec = prec->prossimo);
        prec->prossimo = tmp;
    }
}

// Inserisci in testa
void inserisciInTesta(List* lista, int valore) {
    
    List* tmp = malloc(sizeof(struct Nodo));
    
    tmp->dato = valore;
    tmp->prossimo = lista;
    
    lista = tmp;
}

// Visualizza
void visualizza(List* lista) {
    List* tmp = lista;
    
    while (tmp != NULL) {
        printf("%d ", tmp->dato);
        tmp = tmp->prossimo;
    }
}

// Rimuovi (solo 1 valore == valore. Non tutte le ricorrenze)
void rimuovi(List* lista, int valore) {
    List* tmp = lista;
    List* prec = NULL;
    
    if (tmp != NULL && tmp->dato == valore) {
         lista = tmp->prossimo;
        free(tmp);
        return;
    }
    
    while (tmp != NULL && tmp->dato != valore) {
        prec = tmp;
        tmp = tmp->prossimo;
    }
    
    if (tmp == NULL) {
        printf("\nValore non trovato");
        return;
    }
    
    prec->prossimo = tmp->prossimo;
    free(tmp);
}
