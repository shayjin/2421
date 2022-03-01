#include "bit_op.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long take_bits(unsigned long number, int startIndex, int length){
	unsigned long ret;
	if ((startIndex + length) > 64){
		printf("INVALID STARTINDEX OR LENGTH\n");
		exit(1);
	 } else {
		ret = number << startIndex;
		ret = ret  >> (64 - length);
		return ret;
	 }
}
