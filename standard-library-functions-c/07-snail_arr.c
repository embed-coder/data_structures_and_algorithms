/*
                    j == w-l-1
                   /
  l,  *--*--*--*--*
     \            |
      *--*--*--*  *
      |        |  |
      *  *-(*) *  *
      |  |     |  |
      * (*)-*--*  *
      |           |
     (*)-*--*--*--*
     /             \
   4,0              i == w-l
   l++, (*) = w-l,l
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define DEFAULT 5

void printarr(int *a[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("  %d", a[i][j]);
        printf("\n");
    }
}
int main(int argc, char* argv[])
{
    int w = DEFAULT; // the wall
    int n = pow(DEFAULT, 2);
    int l = 0; // level
    int i = 0, j = 0;
    int a[DEFAULT][DEFAULT];
    int v = 1; // value
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    a[i][j++] = v++;
    while (1) {
        printf("(%d, %d), v: %d\n", i, j, v);
        a[i][j] = v++;
        if (v > n)
            break;
        if (i == l) {
            if (j < w - l - 1)
                j++;
        } else if (i == w - l - 1) {
          if (j > l)
              j--;
        } else {
            if (j == w - l - 1)
                if (i < w - l - 1)
                    i++;
            else if (j == l)
                if (i > l)
                    i--;
        }
        if (i == w - l && j == l)
            l++;
    }

    printarr(a, w);
}