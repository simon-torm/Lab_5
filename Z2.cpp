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
	int rows_B, columns_B;
	int** mas_A;
	int** mas_B;
	int** mas_C;
	int i, j, t;
	
	int sum, size;
	
	//initialization mas_A
	printf("\nEnter the number of COLUMNS and ROWS for mas_A: ");
	scanf("%d %d", &rows_A, &columns_A);
	
	mas_A = new int * [rows_A];
	
	for(i = 0; i < rows_A; i++) {
		mas_A[i] = new int[columns_A];
	}
	
	printf("\n\tMAS_A: \n");
	enterMas(mas_A, rows_A, columns_A);
	
	//initialization mas_B
	printf("\nEnter the number of COLUMNS and ROWS for mas_B: ");
	scanf("%d %d", &rows_B, &columns_B);
	
	mas_B = new int * [rows_B];
	
	for(i = 0; i < rows_B; i++) {
		mas_B[i] = new int[columns_B];
	}
	printf("\n\tMAS_B: \n");
	enterMas(mas_B, rows_B, columns_B);
	
	//print mas
	printf("\nMAS A:\n");
	printMas2(mas_A, rows_A, columns_A);
	printf("\nMAS B:\n");
	printMas2(mas_B, rows_B, columns_B);
	
	//Check columns and rows
	if(columns_A != rows_B) {
		printf("\nWrong size matrices!");
		return -1;
	}
	size = rows_A;
	
	//initialization mas_C
	mas_C = new int * [columns_A];
	for(i = 0; i < columns_A; i++) {
		mas_C[i] = new int[rows_B];
	}
	
	//multiplication
	for(i = 0; i < rows_A; i++) {
		for(j = 0; j < columns_B; j++) {
			sum = 0;
			for(t = 0; t < size; t++) {
				sum += mas_A[i][t] * mas_B[t][j];
			}
			
			mas_C[i][j] = sum;
		}		
	}
	
	printf("\nMAS C:\n");
	printMas2(mas_C, rows_A, columns_B);
	
	
	return 0;
}