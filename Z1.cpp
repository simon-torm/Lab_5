#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterMas(int** mas, int n1, int n2)
{
	int i, j;
	
	for(i = 0; i < n1; i++) {
		for(j = 0; j < n2; j++) {
			printf("\tmas[%d][%d] = ", i, j);
			scanf("%d", &mas[i][j]);
		}
		printf("\n");
	}
}

void printMas(int* mas, int n)
{
	int i;
	
	for(i = 0; i < n; i++) {
		printf("\t%d", mas[i]);
	}
	printf("\n");
}

void printMas2(int** mas, int n1, int n2)
{
	int i, j;
	
	for(i = 0; i < n1; i++) {
		for(j = 0; j < n2; j++)
			printf("\t%d", mas[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int rows_A, columns_A;
	int size_vector;
	int** mas_A;
	int* vector;
	int* vector_X;
	int i, t;
	
	int sum;
	
	//initialization mas_A
	printf("\nEnter the number of COLUMNS and ROWS for mas_A: ");
	scanf("%d %d", &rows_A, &columns_A);
	
	mas_A = new int * [rows_A];
	
	for(i = 0; i < rows_A; i++) {
		mas_A[i] = new int[columns_A];
	}
	
	printf("\n\tMAS_A: \n");
	enterMas(mas_A, rows_A, columns_A);
	
	//vector
	printf("Enter size of vector:");
	scanf("%d", &size_vector);
	vector = new int[size_vector];
	
	printf("\n\tVECTOR: \n");
	for(i = 0; i < size_vector; i++) {
		printf("\n[%d] = ", i);
		scanf("%d", &vector[i]);
	}
	
	//print mas
	printf("\nMAS A:\n");
	printMas2(mas_A, rows_A, columns_A);
	printf("\nVector:\n");
	printMas(vector, size_vector);
	
	//Check columns and rows
	if(columns_A != size_vector) {
		printf("\nWrong size vector!");
		return -1;
	}
	
	//initialization vector_X
	vector_X = new int [rows_A];
	
	//multiplication
	for(i = 0; i < rows_A; i++) {
		sum = 0;
		for(t = 0; t < size_vector; t++) {
			sum += mas_A[i][t] * vector[t];
		}
		vector_X[i] = sum;
	}
	
	printf("\nVECTOR X:\n");
	printMas(vector_X, rows_A);
	
	free(mas_A);
	free(vector);
	free(vector_X);
	
	
	return 0;
}