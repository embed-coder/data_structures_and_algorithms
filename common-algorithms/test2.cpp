#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char * number_cardinality( int my_num ) {
    //Insert your code here 
    if ((my_num % 10) == 0) {
        return "zero";
    } else if ((my_num % 5) == 0) {
        return "five";
    } else if ((my_num % 2) == 0) {
        return "even";
    } else {
        return "odd";
    }
}


int main() {

    return 0;
}