#include <stdio.h>

/*
	Cos'è ADT: Abstract Data Type, ovvero tipo di dati astratto
	viene utilizzato per indicare una struttura dati con le relative 
	operazioni, senza specificare un'implementazione.
	
	- - - -
	STACK = una delle più utili strutture dati standard.
	Segue il funzionamento LIFO (last-in-first-out) 
	
*/

#define	 MAX_LEN  1000
#define	 EMPTY	 -1
#define  FULL 	 (MAX_LEN - 1)

typedef  enum boolean {false, true}  boolean;  //ridenominiamo enum boolean in: boolean

//Struct contenente il membro array s e il membro top di tipo int (il tipo struct stack diventa: stack)
typedef struct stack {
	char s[MAX_LEN];
	int  top;
} stack;


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Il valore top della struttura è inizializzato a EMPTY (-1), concettualmente cancella il contenuto dello stack
void reset(stack *stk){
	stk -> top = EMPTY;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Simula il push nello stack, quindi il numero di valori al suo interno(top), aumenta. da -1 a 0 per esempio.
void push (char c, stack *stk){
	stk -> top++;
	stk -> s[stk -> top] = c; 	//Inserisce all'interno della stringa in posizione top, il carattere c.
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Ritorno il valore del char nella stringa in posizione top, e infine decrementa top
char pop (stack *stk){
	return (stk -> s[stk -> top--]) ;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Ritorno il valore char nella posizione top della stringa
char top (const stack *stk){
	return (stk -> s[stk -> top]);
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Verifica se lo stack è vuoto
boolean empty(const stack *stk){
	return ((boolean) (stk -> top == EMPTY)) ;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//Verifica se lo stack è pieno
boolean full(const stack *stk){
	return ((boolean) (stk -> top == FULL)) ;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
