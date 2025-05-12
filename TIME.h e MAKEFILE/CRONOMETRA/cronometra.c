#include "head.h"

int main(void) {
    long i;
    float  a, b = 3.333, c = 5.555;
    double x, y = 3.333, z = 5.555;
    
    printf("Number of multiplies: %d\n\n", N);
    printf("Type float: \n\n");
    start_time();
    
    for (i = 0; i < N; ++i)
        a = b * c;
    prn_time();
    printf("Type double:\n\n"); 
    for (i = 0; i < N; ++i)
        x = y * z;
    prn_time();
    return 0;
}
