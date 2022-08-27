// C program to find factorial of given number
#include<stdio.h>

// function to find factorial of given number
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// function to find factorial of given number
unsigned int factorial1(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    printf("Factorial of %d is %d\n", num, factorial1(num));
    return 0;
}

