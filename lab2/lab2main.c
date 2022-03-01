#include <stdio.h>
#include <stdlib.h>
#include "bit_op.h"

int main(int argc, char **args){
	unsigned long number, ret;
	int startIndex, length, i;
	
	printf("How many numbers do you need to compute? ");
	scanf("%d", &ret);
	for (i = 0; i < ret; ++i){
		printf("Please enter number, startIndedx, and length (seperated by commas): ");
        	scanf("%lu, %d, %d", &number, &startIndex, &length);
		printf("Number after shifting: %lu\n", take_bits(number, startIndex, length));
	}
	return 0;	
}	
