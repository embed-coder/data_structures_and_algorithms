/* Bit operation
All the operations relate to bit (binary format data)
 */
// Example program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// p: mask, n: group
#define BVAL(n)   (1L << (unsigned int)n)           // number value when enable bit index
#define CBIT(p, n) (p = p & ~(1L << (unsigned int)n))    // Set bit
#define SBIT(p, n) (p = p | (1L << (unsigned int)n))     // Clear bit
#define GBIT(p, n) ((p) & (1L << (unsigned int)n))     // Get bit

int main()
{
    unsigned int n = 0;
    unsigned int p = 2;
    printf("BVAL(%d) = ", n);
    printf("%ld\n", BVAL(n));

    printf("SBIT(%d, %d) = ", p, n);
    printf("%d\n", SBIT(p, n));

    // printf("CBIT(%d, %d) = ", p, n);
    // printf("%d\n", CBIT(p, n));

    printf("GBIT(%d, %d) = ", p, n);
    printf("%ld\n", GBIT(p, n));
}

/* 
BVAL(1) = 2
SBIT(1, 1) = 3
CBIT(3, 1) = 1
GBIT(1, 1) = 0
 */