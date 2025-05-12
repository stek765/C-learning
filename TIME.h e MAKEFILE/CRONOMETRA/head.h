#ifndef HEAD_H

#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASTRING 100
#define N 100000000

typedef struct{
    clock_t begin_clock, save_clock;
    time_t  begin_time,  save_time;
}time_keeper;

extern time_keeper tk;

void start_time(void);
double prn_time(void);

#endif
