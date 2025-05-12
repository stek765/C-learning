#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Nodo {
    int dato;
    struct Nodo* prossimo;
};

//Personalmente SEMBRA piu comodo usare il puntatore* qui, ma non lo è (ti consiglio liste_modo1)
typedef struct Nodo* List;

void inserisciInCoda(List* lista, int valore);
void inserisciInTesta(List* lista, int valore);
void visualizza(List lista);
void rimuovi(List* lista, int valore);

int main(int argc, char* argv[]){
    
    List nuovoNodo = NULL;
    srand(time(NULL));
    int new_value = 1 + rand()%(100 - 1 + 1);
    
    inserisciInCoda(&nuovoNodo, new_value);
    inserisciInCoda(&nuovoNodo, new_value);
    inserisciInCoda(&nuovoNodo, 77);
    inserisciInTesta(&nuovoNodo, new_value);
    visualizza(nuovoNodo);

    rimuovi(&nuovoNodo, 77);
    visualizza(nuovoNodo);
    
    free(nuovoNodo);
}

// Inserisci in coda
void inserisciInCoda(List* lista, int valore) {
    
    List tmp;
    List prec;
    
    tmp = malloc(sizeof(struct Nodo));
    if (tmp == NULL)
        printf("Error malloc tmp");
    
    tmp->dato = valore;
    tmp->prossimo = NULL;
    
    if (*lista == NULL)
        *lista = tmp;
    else{
        for (prec = *lista; prec->prossimo != NULL; prec = prec->prossimo);
        prec->prossimo = tmp;
    }
}

// Inserisci in testa
void inserisciInTesta(List* lista, int valore) {
    
    List tmp = malloc(sizeof(struct Nodo));
    tmp->dato = valore;
    tmp->prossimo = *lista;
    
    *lista = tmp;
}

// Visualizza
void visualizza(List lista) {
    List tmp = lista;
    
    while (tmp != NULL) {
        printf("%d ", tmp->dato);
        tmp = tmp->prossimo;
    }
}

// Rimuovi (solo 1 valore == valorre. Non tutte le ricorrenze)
void rimuovi(List* lista, int valore) {
    List tmp;
    List prec;
    
    if ((*lista)->dato == valore){
        tmp = *lista;
        *lista = (*lista)->prossimo;
    } else {
        prec = *lista;
        tmp = (*lista)->prossimo;
        while (tmp != NULL && tmp->dato != valore){
            prec = tmp;
            tmp = tmp->prossimo;
        }
        if (tmp == NULL) {
            printf("\nValore non trovato");
            return;
        }
        prec->prossimo = tmp->prossimo;
    }
    free(tmp);
    printf("\n\nNodo rimosso\n\n");
}
