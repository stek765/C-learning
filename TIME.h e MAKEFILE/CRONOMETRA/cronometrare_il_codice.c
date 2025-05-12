#include "head.h"

time_keeper tk;

void start_time(void){
    tk.begin_clock = tk.save_clock = clock();
    tk.begin_time = tk.save_time = time(NULL);
}

double prn_time(void){
    char   s1[MASTRING], s2[MASTRING];
    int    field_width, n1, n2;
    double clocks_per_second = (double) CLOCKS_PER_SEC,
    user_time, real_time;
    
    user_time = (clock() - tk.save_clock) / clocks_per_second;
    real_time = difftime(time(NULL), tk.save_time);
    tk.save_clock = clock();
    tk.save_time = time(NULL);
    
    //Stampa in modo chiaro i valori trovati
    
    n1 = sprintf(s1, "%.1f", user_time);
    n2 = sprintf(s2, "%.1f", real_time);
    field_width = (n1 > n2) ? n1 : n2;
    printf("%s%*.1f%s\n%s%*.1f%s\n\n",
        "User time: ", field_width, user_time, " seconds",
        "Real time: ", field_width, real_time, " seconds");
    return user_time;
}


// UNA VOLTA SCRITTO QUESTO CODICE CHE PUÒ TORNARE MOLTO UTILE
// SCRIVO A TERMINALE:
/*
cc -c cronometrare_il_codice.c -o cronometrare_il_codice.o
cc -c cronometra.c -o cronometra.o

ar ruv u_lib.a cronometrare_il_codice.o cronometra.o
ranlib u_lib.a

cc u_lib.a -o cronometra_executable

./cronometra_executable

*/