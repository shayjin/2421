#include <stdio.h>

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char *argv[]){
	int num1 = atoi(argv[1]), num2 = atoi(argv[2]);
	swap(&num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}
