#include<stdio.h>
#include<stdlib.h>
#include<ranlib.h>
#include<time.h>
#include<string.h>

#define AUTO 1
#define MOTO 2
#define VAN 3
#define POSTI 12

struct parcheggio
{
    /* data */
    int veicolo; 
    int posti;
};

typedef struct parcheggio p;

// after the struct is defined, parcheggio becomes a usable variable type. (struct parcheggio aliased as p)

void AggiungiPosti(p* structP, int postig);
void AggiungiVeicolo(p* structP, int veicolo);
int  ParcheggioFull(p* structP);
void VisualizzaLista(p* structP);


//main
int main(int argc, char const *argv[])
{
    p* struct_parcheggio = (p*) malloc(sizeof(p));
    int tipoVeicolo = AUTO; 
    
    AggiungiPosti(struct_parcheggio, POSTI);
    
    do{
        AggiungiVeicolo(struct_parcheggio, tipoVeicolo);
        if      (tipoVeicolo == AUTO)
            tipoVeicolo = MOTO;
        else if (tipoVeicolo == MOTO)
            tipoVeicolo = VAN;
        else if (tipoVeicolo == VAN)
            tipoVeicolo = AUTO;
    }while(ParcheggioFull(struct_parcheggio) == 0);
    
    VisualizzaLista(struct_parcheggio);
    
    free(struct_parcheggio);
    return 0;
}

//funzioni
void AggiungiPosti(p* structP, int postig){
    structP->posti = postig;
}

void AggiungiVeicolo(p* structP, int veicolo){
   if (veicolo == AUTO && structP->posti >= 1)
    {
        structP->veicolo += 1;
        structP->posti -= 1;
    }
    else if (veicolo == MOTO && structP->posti >= 2)
    {
        structP->veicolo += 1;
        structP->posti -= 2;
    }
    else if (veicolo == VAN && structP->posti >= 3)
    {
        structP->veicolo += 1;
        structP->posti -= 3;
    }
    else
    {
        printf("Parcheggio pieno per questo tipo di veicolo\n");
    }
}

int ParcheggioFull(p* structP){
    if(structP->posti == 0)
        return 1;
    return 0;
}

void VisualizzaLista(p* structP){
    if(structP != NULL)
        printf(" \n num veicolo -> %d \n posti -> %d ", structP->veicolo, structP->posti);
}