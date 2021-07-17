#include<stdio.h>

int main(void)
{
	int arr[5][4] = { {26,26,23,5},{26,25,28,9},{23,25,28,6},{21,24,23,7},{23,26,29,10} };
	int i, j;
	int sum[5] = { 0 };
	double avr[4];
	double temp = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			sum[i] += arr[i][j];
		printf("학 생   %d번: ", i+1);

		for (j = 0; j < 4; j++)
			printf("%5d ", arr[i][j]);
		printf("==> %d\n", sum[i]);
	}

	printf("항목별 평균:    ");
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 5; i++)
			temp += arr[i][j];

		avr[j] = temp / 5;
		printf("%5.2f ", avr[j]);
		temp = 0;
	}
	return 0;
}