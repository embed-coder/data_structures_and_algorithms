// C program to check if a
// number is prime

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char isPrime(int a)
{
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

char isPrime1(int a)
{
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv)
{
    int n;

    if (argc > 1)
        n = atoi(argv[1]);

    //~ if (isPrime(n) == 1) {
    if (isPrime1(n) == 1) {
        printf("%d is a prime number\n", n);
    }
    else {
        printf("%d is not a prime number\n", n);
    }

    return 0;
}