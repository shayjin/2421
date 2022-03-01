#include <stdio.h>

int main(){
	int size = 20;
	int array[20];
	int i;

	printf("Print all elemtns in the array: \n");
	for (i = 0; i < size; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}

	printf("\n");
	return 0; 
}
