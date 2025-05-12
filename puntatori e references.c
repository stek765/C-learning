#include <stdio.h>
#define R 1
#define C 3

/*
    Perchè usare i puntatori? Semplicemente perchè quando per esempio
    richiami una funzione e gli passi dei parametri, quello che gli stai
    passando in realtà è una "copia" dei tuoi dati. 

    Utilizzando i puntatori invece, gli passi l'indirizzo in memoria
    e quindi l'effettivo valore originale che verrà già modificato nella
    funzione senza ricopiare potenzialmente dei dati grandi per svolgere un'operazione elementare
*/
    
int main(int argc, char *argv[]) {

    int n = 10;
    
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  I 3 MODI PRINCIPALI PER USARE I PUNTATORI: 
    int  *p = &n;
    int **g = &p;
    int  *q = &(*p);
    
    // Stampa i valori puntati da p, g, e q
    printf("%d, %d, %d\n", *p, **g, *q);
    // Stampa gli indirizzi di memoria di n, p, e q
    printf("%p, %p, %p\n", (void *)p, (void *)*g, (void *)q);

    // - - - - - - - - - - - - - - - - - - - - - -
    //modifico i valore della n così: (modificano tutti n)
    *p  = 20;
    **g = 30;
    *q  = 40;
    
    // Stampa i valori puntati da p, g, e q
    printf("\n%d , %d, %d", *p, **g, *q);
    // Stampa gli indirizzi di memoria di n, p, e q
    printf("\n%p, %p, %p\n\n", (void *)p, (void *)*g, (void *)q);

    printf("\n - - - -\n");
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// RELAZIONE TRA ARRAY E PUNTATORI

    int array[] = {1,2,3,4,5,6,7,8,9};
    int *arrpointer[9]; 
    // modo per trovare la lenght di qualcosa in c
    int lenght = sizeof(array) / sizeof(array[0]);
    int i;
    
    //stampo array nel modo normale
    for (i = 0; i < lenght; i++){
        printf(" %d ", array[i]);
        //assegno ad ogni cella di arrpointer l'indirizzo di array[i]
        arrpointer[i] = &array[i]; //non centra con la stampa
    }
    printf("\n\n");
    //stampo array coi puntatori (al contrario perchè no..)
    for (lenght--; lenght > -1 ; lenght--){
        printf(" %d |", *(array+lenght));
        printf("  %d  ", *arrpointer[lenght]);
        printf("\n");

    }
    
    int  *c = array + 6;   // uguale a fare *c = &array[0] + i;
    int **d = &c;
    int  *f = &(*c);
    
    printf("\n %d, %d, %d\n", *c, **d, *f);
    
    //quindi in generale se devo utilizzare i valori di *c, a destra dell' = non uso puntatori
    //mentre se devo modificare gli indirizzi, o ciò a cui qualcosa punta, li utilizzo insieme anche a &
    
    printf("\n - - - -\n");
    /* - - - - - - - - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - - - - - - - - */
    // BONUS: puntatori a stringhe e le funzioni strcat, strcmp, strcpy, strlen
    char* str = "abc";
    
    printf("\n str -> %s,  *str +1 -> %s \n", str ,str + 1);
    
    /*
    strcat(<#char *__s1#>, <#const char *__s2#>);
    strcmp(<#const char *__s1#>, <#const char *__s2#>);
    strcpy(<#char *__dst#>, <#const char *__src#>);
    strlen(<#const char *__s#>);
    */
    
    
    /* - - - - - - - - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - - - - - - - - */
    // BONUS: puntatori a matrici     char* str = "abc";

    int m2[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    
    printf("\n - - - -\n");
    // Stampa la matrice
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d ", m2[i][j]);
        }
        printf("\n"); // Vai a capo dopo ogni riga
    }
    

    // 3 metodi per passare una matrice ad una funzione
    int funzione(/*prende una matrice*/);
    int funzione(int m3[2][7]);
    int funzione(int m4[][7]);
    int funzione(int (*m5)[7]);
    
    
    // Espressioni equivalenti ad m2[i][j] (R e C definiti sopra)
    printf("\n Posizione (1, 3): \n");
    printf(" %d\n",*(m2[R] + C)          );
    printf(" %d\n", (*(m2 + R))[C]          );
    printf(" %d\n",  *((*(m2 + R)) + C)      );
    printf(" %d\n",  *(&m2[0][0] + 4*R + C) );
    
    
    
    
    
    
    
}

