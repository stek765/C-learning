#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int  c, i, letter[26];
	FILE *ifp, *ofp;
	
	//controllo n. parametri (==3) 
	if(argc != 3){
		printf("\n%s%s%s\n\n%s\n%s\n\n",
			    "Usage:   ", argv[0]," infile  outfile",
				"The uppercase letters in infile will be counted.",
				"The results will be written in outfile.");
		exit(1);
	}
	
	//apro il file di input e un file di output
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");
	
	//inizializzo l'array a zero
	for (i = 0; i < 26; ++i)
		letter[i] = 0;
	
	//trovo le lettere maiuscole
	while ((c = getc(ifp)) != EOF) // getchar e getc sono simili, ma il secondo  in stdio.h 
		if (c >= 'A' && c <= 'Z')  // e riceve un parametro di tipo puntatore a FILE
		
			++letter[c - 'A']; /* Incremento la posizione con la lettera trovata */
	
	//stampo i risultati
	for (i = 0; i < 26; ++i) {
		if (i % 6 == 0)
			putc('\n', ofp);
		fprintf(ofp, "%c:%5d   ", 'A' + i, letter[i]);
	}
	putc('\n', ofp);
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
