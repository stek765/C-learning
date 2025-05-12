
// Posso usare anche execl per cambiare processo (non torno più al padre, il nuovo processo
// lo sostituisce completamente)

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	int choice = 0;
	
	printf("%s\n%s\n%s",
		"The parent process will be overlaid.",
		"You have a choice.",
		"Input 1 or 2: ");
	scanf("%d", &choice);
	putchar('\n');
	if (choice == 1)
		execl("pid_e_fork", "pid_e_fork", NULL);
	if (choice == 2)
		execl("spawn", "spawn", NULL);
	printf("ERROR");
	
	//Si può usare al posto di execl, anche spawn(0/1/2, stessi parametri)
	//con 0 = padre aspetta il figlio, 1 = esecuzione concorrente, 2 = il figlio sostituisce il padre. 
	return 0;
}

//QUESTO PROG NON FUNZIONA MA È CORRETTO

