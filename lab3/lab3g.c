#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int row = atoi(argv[1]), col = atoi(argv[2]);
	int** array = (int**)malloc(sizeof(int*)*row);
	int i, j;
	printf("Print all elements: \n");
	for (i = 0; i < row; i++) {
		array[i] = (int*)malloc(sizeof(int)*col);
		for (j = 0; j < col; j++) {
			array[i][j] = i * j;
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	
	printf("Print the address of each element: \n");
	for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                        printf("%dlu ", &array[i][j]);
                }
                printf("\n");
        }
	
	printf("Print array[0], array[1], ..., array[9]: \n");
	for (i = 0; i < row; i++) {
		printf("array[%d]: ", i);
                for (j = 0; j < col; j++) {
                        printf("%d ", array[i][j]);
                }
                printf("\n");
        }
	free(array);	
	return 0;
}
