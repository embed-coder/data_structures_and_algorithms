/* C code below */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool exists(int ints[], int count, int k)
{
    int *item;

    item = (int*) bsearch (&k, ints, count, sizeof (int), cmpfunc);
    if (item != NULL)
        return 1;

    return 0;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = exists(arr, n, x);
    (result == 0) ? printf("Element is not present in array\n")
                : printf("Element is present int the array\n");
    return 0;
}