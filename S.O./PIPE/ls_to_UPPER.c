#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//La Popen, crea una pipe. Si può usare solo in modo sequenziale (no indici)
int main(int argc, char *argv[]) {
    int c;
    FILE *ifp;
    
    ifp = popen("ls ~/Desktop", "r");
    
    while ((c = getc(ifp)) != EOF)
        putchar(toupper(c));
    
    //chiude la pipe
    pclose(ifp);
    return 0;
}