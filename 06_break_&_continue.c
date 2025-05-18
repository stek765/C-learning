#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 2;
	
	// con break, esco dal ciclo, con continue salto tutte le istruzioni di quella iterazione
	printf("\n i iniziale -> %d", i);
	for (int j = 0; j < 10; j++){
		if (i == 0)
			break;
		if (j == 1)
			continue;
		i--;
		printf("\n i alla j-esima iterazione -> ( %d, %d ) ", i , j ); 
		// i = 2, quindi dopo 2 iterazioni teoricamente i == 0 -> break
		// invece con j == 1 -> continue, saltiamo l'i-- e quindi 
		// avremo i == 0 dopo 3 iterazioni.
	}
}