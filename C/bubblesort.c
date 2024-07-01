#include <stdio.h>
#define N 10

void swap(int *, int *);

int main(int argc, char *argv[]) {
	
	//algoritmo bubblesort
	int arr[] = {4, 7, 6, 5, 9, 4, 8, 6, 13, 2}; 
	int i, j;
	
	for (i = 0; i < N-1; ++i){
		for (j = 0; j < N - 1 - i; j++){ 
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
	
	for (i = 0; i < N; i++){
		printf("%d ", arr[i]); // Aggiunto spazio per la formattazione
	}
	printf("\n"); // Aggiunto per una riga vuota alla fine della stampa
}

void swap(int *p, int *q){
	int tmp;
	
	tmp = *p;
	*p = *q;
	*q = tmp;
}
