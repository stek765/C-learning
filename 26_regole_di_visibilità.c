#include <stdio.h>

int main(int argc, char *argv[]) {
	// fuori dallo scope
	int a = 1, b = 2, c = 3;
	printf("   a | b | c   \n\n%4d%4d%4d\n", a, b, c);
	
	/* - - - - - - - - - -
	  PRIMO scope  */	
	{
		int b = 4;
		float c = 5.0;
		printf("%4d%4d%5.1f\n", a, b, c);
		a = b;
				/* - - - - - - - - - -
				   SECONDO scope */
				{
					int c;
					c = b; 
					printf("%4d%4d%4d\n", a, b, c);
				}
				/* - - - - - - - - - -
				   FINE SECONDO scope */	
		printf("%4d%4d%5.1f\n", a, b, c);
	}
	/* - - - - - - - - - -
	FINE PRIMO scope */	
	printf("%4d%4d%4d\n", a, b, c);
}

/* SI UTILIZZA QUESTA COSA PER IL DEBUGGING: 

	{								// inizio del debg 
		static int cnt = 0;
		printf("*** debug: cnt = %d  v = %d\n", ++cnt, v);
	}

*/