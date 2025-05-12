#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


#define MAXSTRING 100

// Le varie librerie su mac, si trovano (dopo aver installato homebrew, e la Xcode command line tools):
// PATH: /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers


void cntrol_c_handler(int sig);
int fib(int n);

/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
// MAIN
int main(void) {
	int i;
	
	// This line sets up a signal handler for the SIGINT signal, which is typically sent
	// to a process when the user presses CTRL+C in the terminal. 
	signal(SIGINT, cntrol_c_handler);
	for (i = 0; i < 46; ++i) {
		printf("fib(%2d) = %d\n", i, fib(i));
	}
	return 0;
}
/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
// CNTROL_C_HANDLER
// Controlla con un segnale la pressione di CTRL+C per fermare il programma !!
void cntrol_c_handler(int sig){
	char answer[MAXSTRING];
	printf("\n\n%s%d\n\n%s",
		"Interrupt received!  Signal = ", sig,
		"Do you wish to continue or quit? ");
	scanf("%s", answer);
	// Premi c per continuare, in pratica risetta l'handler di ctrl+c e torna ad iterare nel for
	if (*answer == 'c')
		signal(SIGINT, cntrol_c_handler);
	// Premi un qualsiasi altro carattere per endare il programma
	else
		exit(1);
}
/* - - - - - - - - - - - - - - - *//* - - - - - - - - - - - - - - - */
// FIB
// Printa la serie di fibonacci
int fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n-1) + fib(n-2);
}