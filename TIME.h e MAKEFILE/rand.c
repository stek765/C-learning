#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i, n; 
    
    printf("\n%s\n%s",
        "Some randomly distributed integers will be printed.",
        "How many do you want to see?  ");
    scanf("%d", &n);
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Every 10 numbers generate put \n
    for(i = 0; i < n; ++i){
        if (i % 10 == 0)
            putchar('\n');
        
        //                  - - - - - - - - - - - - - - - - -
        // spaced 5d, -->>>| MIN + rand() % ( MAX - MIN + 1) |
        //                  - - - - - - - - - - - - - - - - -
        printf("%5d ",      1 + rand() % (77 - 1 + 1));
        
        
    }
    printf("\n\n");
    return 0;
}
