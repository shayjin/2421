#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	int *array = (int *)malloc(size*10);
	int i;

	printf("Print all elements in the array: ");
	for(i = 0; i < size; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}
	
	printf("\n");
	free(array);
	return 0;

}
