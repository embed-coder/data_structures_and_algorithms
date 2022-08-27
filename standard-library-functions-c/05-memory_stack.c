#include <stdio.h>

int main () {
    int a = 5;  // Stack
    int *p;     // Heap

    p = &a;     // p will be stored in Stack also
    printf ("&a = %x, p = %x\n", &a, p);

    p = NULL;
    free(p);

    return 0;
}