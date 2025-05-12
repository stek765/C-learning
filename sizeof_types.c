#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("The size of some fundamental types is computed. \n\n");
	
	printf("       char:%3lu byte \n",  sizeof(char));
	printf("      short:%3lu byte \n",  sizeof(short));
	printf("        int:%3lu byte \n",  sizeof(int));
	printf("       long:%3lu byte \n",  sizeof(long));
	printf("   unsigned:%3lu byte \n",  sizeof(unsigned));
	printf("      float:%3lu byte \n",  sizeof(float));
	printf("     double:%3lu byte \n",  sizeof(double));
	printf("long double:%3lu byte \n",  sizeof(long double));
	
	printf("\n - - - - - - - - - - \n   ESEMPIO CON 77:\n - - - - - - - - - -  \n\n");
	
	char  		c = 77;
	short 	    s = 77;
	int         i = 77;
	long        l = 77;
	unsigned    u = 77;
	float       f = 77.2;
	double      d = 77.2;
	long double ld = 77.2;
	
	printf("       char: %d\n", c);
	printf("      short: %d\n", s);
	printf("        int: %d\n", i);
	printf("       long: %ld\n", l);
	printf("   unsigned: %u\n", u);
	printf("      float: %f\n", f);
	printf("     double: %lf\n", d);
	printf("long double: %Lf\n", ld);
	
	
	return 0;
}