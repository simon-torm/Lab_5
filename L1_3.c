#include <stdio.h>
#define SIZE 9


void print_mas2(int n1, int n2, int (*mas)[SIZE])
{
	int i1, i2;
	for(i1 = 0; i1 < n1; i1++) {
		printf("\n\t");
		for(i2 = 0; i2 < n2; i2++)
			printf(" %d", mas[i1][i2]);
	}
}

void SortMas(int n1, int n2, int (*mas)[SIZE])
{
	int i1, i2;
	for(i1 = 0; i1 < n1; i1++)
		for(i2 = 0; i2 < n2; i2++) {
			if(i2 < i1)
				mas[i1][i2] = 0;
			else if(i2 < SIZE - i1)
				mas[i1][i2] = 1;
			else
				mas[i1][i2] = 0;
		}	
}

int main()
{
	int mas[SIZE][SIZE];
	
	SortMas(SIZE, SIZE, mas);
	print_mas2(SIZE, SIZE, mas);
	
	return 0;
}