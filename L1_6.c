#include <stdio.h>
#define SIZE 9

void printMas2(int n1, int n2, int (*mas)[SIZE])
{
	int i, j;
	for(i = 0; i < n1; i++) {
		printf("\n\t");
		for(j = 0; j < n2; j++)
			printf(" %d", mas[i][j]);
	}
}

void SortMas(int (*mas)[SIZE])
{
	int i, j;
	
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++)
			if(i <= SIZE / 2) {
				if((j >= i) && (j < (SIZE - i)))
					mas[i][j] = 0;
				else
					mas[i][j] = 1;
			} else {
				if((j <= i) && (j >= SIZE - i - 1))
					mas[i][j] = 0;
				else
					mas[i][j] = 1;
			}
	}
}

int main(void)
{
	int mas[SIZE][SIZE];
	
	SortMas(mas);
	printMas2(SIZE, SIZE, mas);
	
	return 0;
}