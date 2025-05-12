#include <stdio.h>

//Compilando questo file da terminale con -S, crea l'assembly:
//gcc -S nomefile

//Si può fare l'elaborato in c e poi convertirlo in un attimo
int main(int argc, char *argv[]) {
	int n = 3, n1 = 2;
	
	int d = n + n1;
	
	printf("Hello world, this number -> %d", d);
}