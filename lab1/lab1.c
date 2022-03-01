#include <stdio.h>
#include "local_file.h"

int main(void)
{
	unsigned int maxEntries;
	int getchar_return_value;

	printf("This program reads in a number, then a series of keyboard characters. The number\n");
	printf("indicates how many characters follows. The number can be no higher than %d.\n", MAX_NUM);
	printf("Then the specified number of characters follow. These characters can be any\n");
	printf("key on a regular keyboard.\n");

	printf("Please enter the number of entries, followed by the enter/return key: ");
	getchar_return_value = getchar();
		
	if(getchar_return_value != '\n'){
		maxEntries = getchar_return_value - '0';
		getchar_return_value = getchar();
		if(getchar_return_value != '\n'){
			maxEntries = maxEntries*10 + getchar_return_value - '0';			getchar();
		}
	}
	else maxEntries=MAX_NUM;
	
	if(maxEntries > MAX_NUM){
		printf("Specified number of characters is invalid. It must be between 1 and %d.\n", MAX_NUM);
		return(0);
	}

	#ifdef DEBUG
		print(" entering function\n");
	#endif
		print_chars(maxEntries);
	#ifdef DEBUG
		printf("returned from function\n");
	#endif
		return(0);

}

