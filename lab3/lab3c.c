#include <stdio.h>
int main() {
	int size = 20;
	int array[20];
	int i;
	printf("Print all elements in the array: ");
	for(i = 0; i < size; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\nYour program should print the address of each element in the following two ways: &array[i]: ");
	for(i = 0; i < size; i++){
		printf("%lu ", &array[i]);
	}
	printf("\narray + i: ");
	for(i = 0; i < size; i++){
		printf("%lu ", array + i);
	}
	printf("\n");
	return 0;
}
