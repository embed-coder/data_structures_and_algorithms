#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int nearestZero(int ts[], int size)
{
    int tmparr[size + 1];
    int* zeroItm;
    int key = 0;
    int zeroIdx;
    int lzero;
    int rzero;
    int diff;

    memcpy(tmparr, ts, size * sizeof(int));
    tmparr[size] = 0;

    printArray(ts, size);
    printArray(tmparr, size + 1);

    qsort(tmparr, size, sizeof(int), cmpfunc);
    printArray(tmparr, size + 1);

    zeroItm = (int*) bsearch (&key, tmparr, size + 1, sizeof (int), cmpfunc);
    zeroIdx = zeroItm - tmparr;
    for (int i = zeroIdx - 1; i >= 0; i--)
        if (0 != tmparr[i]) {
            lzero = tmparr[i];
            break;
        }
    for (int i = zeroIdx + 1; i <= size; i++)
        if (0 != tmparr[i]) {
            rzero = tmparr[i];
            break;
        }

    diff = lzero + rzero;
    printf("diff: %d\n", diff);
    if (0 >= diff)
        return rzero;

    return lzero;
}

int main(void)
{
    int arr[] = { -5, -7, 6, 0, 4, -1, 2, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = nearestZero(arr, n);
    printf("Element is nearest zero is %d\n",
                            result);
    return 0;
}

