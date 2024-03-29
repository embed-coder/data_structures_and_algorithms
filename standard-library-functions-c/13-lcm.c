// C program to find LCM of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
        // Everything divides 0
        if (a == 0 || b == 0)
                return 0;

        // Base case
        if (a == b)
                return a;

        // a is greater
        if (a > b)
                return gcd(a-b, b);
        return gcd(a, b-a);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
        return (a * b) / gcd(a, b);
}

// Driver program to test above function
int main()
{
        int a = 15, b = 20;
        printf("LCM of %d and %d is %d \n", a, b, lcm(a, b));
        return 0;
}

