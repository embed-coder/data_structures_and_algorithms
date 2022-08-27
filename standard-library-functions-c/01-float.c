#include <stdio.h>

extern int x = 0;

void main()
{
    {
        int x = 1;
    }
    printf("%d", x);
}