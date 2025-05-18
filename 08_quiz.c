#include <stdio.h>
 void foo(int** a){
         int i;
         for(i=0; i<3; i++)
         (*a)++;
}
 void bar(int* a){
         foo(&a);
         printf("%d\n", *(a)+1);
}
 int main(){
         int data[4] = {1,2,3,4};
         bar(data);
         return 0;
}
