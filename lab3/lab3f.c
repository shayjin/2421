#include <stdio.h>

int main(){
	int row = 10, col = 15;
	int array[10][15];
	int i, j;

	printf("Print all elements: \n");
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			array[i][j] = i * j;
			printf("%d ", array[i][j]);
		}
	}
	
	printf("\n\nYour program should print the address of each element: \n");
	for(i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("%lu ", &array[i][j]);
		}
	}

	printf("\n\nYour program should print array[0], array[1], ..., array[9]: \n");	
	for(i = 0; i < row; i++){
		printf("array[%d]: {", i);
		for(j = 0; j < col; j++){
			printf("%d", array[i][j]);
			if (j + 1 != col){
				printf(", ");
			}
		}
		printf("} ");
	}
	
	printf("\n");
	return 0;
}
