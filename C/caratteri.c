#include <stdio.h>

int main(int argc, char *argv[]) {
	char small = 'b';
	char BIG = 'S';
	
	// esempi di manipolazione caratteri char
	printf("\n%s %c\n%s %c\n%s %c\n%s %c\n%s %c",
			" b        ->", small,
			" b + 1    ->",   small + 1, 
		    " S        ->",   BIG ,
			" b_to_uppercase (b to B) ->",   small - 'a' + 'A',
		    " S_to_lowercase (S to s) ->",   BIG - 'A' + 'a');
	return 0;
}