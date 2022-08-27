#include <stdio.h>

int main() {
    int a = 8;
    int a1 = 9;
    int b[10];

    printf ("b: %x\n", b);
    printf ("&b: %x\n", &b);

    const int *c;
    c = &a;
    // *c = 10; // Error: assignment of read-only location ‘*c’
    printf ("c: %x, *c: %d\n", c, *c);
    int const *d;
    d = &a;
    // *d = 10; // Error: assignment of read-only location ‘*d’
    printf ("d: %x, *d: %d\n", d, *d);
    d = &a1;
    printf ("d: %x, *d: %d\n", d, *d);
    const int const *e;
    e = &a;
    // *e = 10; // assignment of read-only location ‘*e’
    e = &a1;
    printf ("e: %x, *e: %d\n", e, *e);

    return 0;
}