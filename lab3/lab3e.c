#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	int *array = (int *)malloc(size*10);
	int i;
	printf("Print all elemtns in the array: ");
	for (i = 0; i < size; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\nPrint the address of each element in the following two ways: &array[i]: \n");
	for (i = 0; i < size; i++){
		printf("%lu ", &array[i]);
	}
	printf("\narray + i: \n");
	for(i = 0; i < size; i++){
		printf("%lu ", array + i);
	}
	printf("\n");
	free(array);
	return 0;	

}
