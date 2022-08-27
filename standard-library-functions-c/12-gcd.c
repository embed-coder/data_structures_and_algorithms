// C program to find GCD of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Recursive function to return gcd of a and b
int gcd1(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Driver program to test above function
int main()
{
    int a = 10, b = 6;
    printf("GCD of %d and %d is %d \n", a, b, gcd(a, b));
    printf("GCD of %d and %d is %d \n", a, b, gcd1(a, b));
    return 0;
}

