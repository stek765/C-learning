// Utilizzo di INCLUDE: 
#include <stdio.h>
/*  
	#include "filename" 

-> 	il preprocessore la sostituisce con una copia del contenuto del file indicato
	la ricerca avviene prima nella directory corrente e poi in altri punti dipendenti dal sistema*

	#include <filename> 

->  il preprocessore effettua la ricerca solo negli altri punti e non nella directory corrente 

*/


/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
// Utilizzo di DEFINE: 

//semplici
#define N 10
#define SECONDO_PER_DAY (60 * 60 * 24)

//macro più complesse
#define min(x,y)  (((x) > (y)) ? (x) : (y))

#define min4(a,b,c,d)   min(min(a,b), min(c,d))

//per esempressioni lunghe posso andare a capo con '\'
#define FILL(array, sz, type)       \
	if (strcmp(type, "char") == 0)  \
		printf("bella");          
		
#define f 2
#if f < 2
	//lascio gestire l'error 
	#error "Error"
#endif	

//cambia valore della riga (non piu 39, ma 1)
#line 1
/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - *//*

  Per vedere l'output del preprocessore è possibile utilizza il comando:  cc -E  file.c

*/
	

/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
// BONUS: ctype.h (libreria con macro per i char)
/* BONUS: Compilazione condizionale ->
	
   #if      constant_integral_expression  (deve essere != 0)
   #ifdef   identifier
   #ifndef  identifier
	
	esempio:

	#define    DEBUG   1  
	#if DEBUG
		printf("debug: a = %d\n", a);
	#endif
	
	oppure 
	
	#define    DEBUG   
	#ifdef DEBUG
		printf("debug: a = %d\n", a);
	#endif
		
*/
		
int main(int argc, char *argv[]) {
	int n = 1, c = -1;
	
	//BONUS: Per risolvere il problema del debugging in mezzo ai commenti:
	
	int d = n - c; /* d = 1 - 1; */
	
	printf("error\n");  /*istruzione 1 a caso*/
	printf("bella\n");   /* 2 */
	printf("c'è stato un errore..forse\n\n- - - - - -\n");  /* fuori */
	
	//Se dovessi usare /* */ per debuggare commentando delle operazioni, esempio: 
	
//	 /*    printf("error\n");  /*istruzione 1 a caso*/      */   -> DA ERRORE (senza le // iniziali)
	
	
	
	//Per evitare questo tipo di accavallamenti tra commenti posso fare così:
#if    d == 0
	printf("error\n"); 
#elif  d == 1
	printf("bella");
#endif	
	printf("c'è stato un errore..forse\n");
	
	
}

/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
//BONUS: la libreria assert.h, questa  macro può essere utilizzata per controllare che 
// il valore di un'espressione sia proprio quello che ci si aspetta