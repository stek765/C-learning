#include <stdio.h>
#include <stdlib.h>

#define N 3

int 	add_vector(int v[]);
void 	error_exit(char *s);
int 	fork (void);
int 	pipe (int pd[2]);
int 	read (int fd, void *buf, unsigned len);
int 	write(int fd, void *buf, unsigned len);

/* FUNZIONAMENTO PIPE

+--------------------+--------------+--------------+--------------------+
| Processo Figlio 1 | Processo Figlio 2 | Processo Figlio 3 |    Pipe      |
+--------------------+--------------+--------------+--------------------+
|                    |                |                		|  Valore 3    |
|                    |                |               		|  Valore 2    |
|                    |                |                		|  Valore 1    |
+--------------------+--------------+--------------+--------------------+

	   PIPE
+----------------+
|    Scrittura   |
| Valore 3       |
| Valore 2       |		FIFO (first-in-first-out), il che significa che i dati scritti prima nella pipe vengono letti per primi.
| Valore 1       |
|    Lettura     |
+----------------+

*/

int main(void) {
	
	int a[N][N] = {{1, 1, 1}, {2, 2, 2},{3, 3, 3}}, 
		i, row_sum, sum = 0,
		pd[2];
	
	// Crea una pipe e verifica sia andata a buon fine
	if  (pipe(pd) == -1)
		error_exit("pipe() failed");
	for (i = 0; i < N; ++i)
		// Fa una fork e verifica sia andata a buon fine
		if (fork() == 0){
			// con la funzione add_vector somma ogni riga della matrice e poi la scrive nella pipe 
			// l'indice i, viene passato anche dopo la fork perchè ricordo, la fork, è una copia del padre
			// i valori vengono "accumulti" nella pipe grazie ad un buffer
			row_sum = add_vector(a[i]);
			if (write(pd[1], &row_sum, sizeof(int)) == -1)
				error_exit("write() failed");
			return 0;
		}
	// Leggo il buffer della pipe e prendo i valori uno ad uno
	for (i = 0; i < N; ++i){
		if (read(pd[0], &row_sum, sizeof(int)) == -1)
			error_exit("read() failed");
		sum += row_sum;
	}
	
	printf("Sum of the array = %d\n", sum);
	return 0;
}

int add_vector(int v[]){
	int i, vector_sum = 0;
	
	for (i = 0; i < N; ++i)
		vector_sum += v[i];
	return vector_sum;
}

void error_exit(char *s){
	fprintf(stderr, "\nERROR: %s - bye!\n", s);
	exit(1);
}