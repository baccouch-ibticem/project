#include <stdio.h>
 #include <stdlib.h>
int main() {
   int nbr, i, j, k;
  
 int tab[8] = {3, 2, 5, 5, 10, 11, 9, 11};
   
 
   for (i = 0; i < 8; i++) {
      for (j = i + 1; j < 8;) {
         if (tab[j] == tab[i]) {
            for ( k= j; k < 8; k++) {
               tab[k] = tab[k + 1];
            }
            nbr--;
         } else
            j++;
      }
   }
 
   printf(" val: ");
   for (i = 0; i < 8; i++) {
      printf("%d ", tab[i]);
   }
   return 0;}
