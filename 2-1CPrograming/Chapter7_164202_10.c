#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x[3][3], y[3][3], sum[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			x[i][j] = rand() % 100;
			y[i][j] = rand() % 100;
		}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sum[i][j] = x[i][j] + y[i][j];

	printf(" x 행렬: \n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf(" %3d", x[i][j]);
		printf("\n");
	}

	printf(" y 행렬: \n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf(" %3d", y[i][j]);
		printf("\n");
	}

	printf(" x + y 행렬: \n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf(" %3d", sum[i][j]);
		printf("\n");
	}
	
	return 0;
}