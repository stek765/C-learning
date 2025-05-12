#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	// Printa le informazioni su i processi del sistema
	system("ps aux");
	
	sleep(1);
	system("clear");
	
	// Per invece prendere il PID di un processo specifico:
	
	
	// Crea un processo figlio, ovvero una copia esatta del processo padre TRANNE CHE PER IL PID
	// e che condivide le stesse risorse del padre
	int fork(void), value;
	
	value = fork();
	
	// Posso scegliere a chi far fare azioni
	if (value == 0)
		printf("\n - - - - -\n FIGLIO");
	else
		printf("\n - - - - -\n PADRE");
	
	// Viene stampato dal processo pare, il PID del figlio
	// Viene stampato dal figlio: 0
	// (non sempre, perchè i processi sono nondeterministici (dipende dalle scelte del processore)
	printf("\n In main: value = %d\n", value);
	
	return 0;
	
}