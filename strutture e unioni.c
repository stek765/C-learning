#include <stdio.h>


//Struttura standard (quando viene creata, viene creato il TIPO, ma non viene allocata memoria finchè non creo variabili):
struct card{
	int numero;
	char carattere;
}c1, c2, prova = { 12 , 'S'};


//creo delle variabili della prima struttura
struct card c3, c4;


//Struttura versione PRO: (cosa cambia: utilizzo la typedef -> quindi dove prima avevo le variabili c1,c2; 
// adesso shortcut è un altro modo per riferirsi al TIPO struct corrispondente -> shortcut var; 
typedef struct{
	int num;
	char car;
} shortcut;

int main(int argc, char *argv[]) {
	//Printo la variabile prova inizializzata gia prima
	printf("\nprinto la variabile struct prova: num ->%d e car ->%c  \n", prova.numero, prova.carattere);
	
	c1.numero = 3;
	c1.carattere = 'c';
	
	c2.numero = 4;
	c3.numero = 5;
	c4.numero = 6;
	c4 = c1;
	
	printf("\nnumero nella struct delle variabili create:\nc1 -> %d \nc2 -> %d \nc3 -> %d \nc4 -> %d ", c1.numero, c2.numero, c3.numero, c4.numero);
	
	/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */
	//Uso di typedef (è standard anche questo)
	
	typedef struct card card;
	//In questo modo al posto di usare struct card, ogni volta che mi serve dichiare una variabile di tipo struct card, mi basta usare il tipo card:
	card c5, c6, c7;
	
	
	/* - - - - - - - - - - - - *//* - - - - - - - - - - - - */
	
	shortcut variab;
	variab.num = 2;
	variab.car = 'f';
}
