#include<stdio.h>
#include<stdlib.h>

void main() {
    int i = 0;

    while (1) {
	switch (i) {
	    case 0:
		printf("case 0\n");
		break;
	    case 1:
		printf("case 1\n");
	    case 2:
		printf("case 2\n");
		break;
	    case 3:
		printf("case 3\n");
		break;
	    default:
		i = -1;
		printf("case default\n");
	}
	printf("**next round**\n");
	i++;
	sleep(1);
    }
}