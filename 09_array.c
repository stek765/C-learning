#include <stdio.h>


int main(int argc, char const *argv[]) {


  int A[] = {1, 3, 3, 2, 4, 4, 4, 4, 4, 4};
  int i, P_inz, P_finl, streak=1, streak_max=0, P_inz_def, P_finl_def;
  printf("\n Array: ");
  for(int j=0; j<10; j++){ 
    printf(" %d ", A[j]);
  }
  
  printf("\n ");
  for (i=0; i<10; i++){
    if(A[i] == A[i+1] && i<10 && streak ==1){
        P_inz = i;  //mi salvo la posizione da dove iniza la streak
        streak++;   //conto la prima ripetizione
    }
    else if(A[i] == A[i+1] && i<10 && streak != 1){
        streak++; //conto il numero di ripetizioni

    }

    else if(A[i] != A[i+1] && i<10 && streak != 1){
      P_finl = i;  // mi salvo la posizione di fine streak
      if(streak_max < streak){
          streak_max = streak;  //mi salvo quanto è durata la streak
          //salvo le posizioni iniziali e finali solo della streak più lunga
          P_finl_def = P_finl;
          P_inz_def = P_inz;
      }
      streak = 1; //resetto la streak
    }

    else if(i == 9){
      P_finl = 9;  // mi salvo la posizione di fine streak
      if(streak_max < streak){
          streak_max = streak;  //mi salvo quanto è durata la streak
          //salvo le posizioni iniziali e finali solo della streak più lunga
          P_finl_def = P_finl;
          P_inz_def = P_inz;
      }
    }
    //scorro l'indice
  }

  printf("\n Streak massima -> %d caratteri, \n - - -\n P0 -> %d , \n Pf -> %d\n - - -\n\n", streak_max, P_inz_def, P_finl_def);
  return 0;
}
