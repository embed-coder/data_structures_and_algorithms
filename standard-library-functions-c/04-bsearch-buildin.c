#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int values[] = { 5, 20, 40, 29, 32, 63 };

int main () {
   int *item;
   int key = 20;

   item = (int*) bsearch (&key, values, 6, sizeof (int), cmpfunc);
   if( item != NULL ) {
      printf("Found item = %d @ %ld\n", *item, item - values);
   } else {
      printf("Item = %d could not be found\n", *item);
   }

   return(0);
}