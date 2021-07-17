#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fill_2d_array(int arr[][5], int row, int ele);

int main(void)
{
	int arr[4][5], ele;
	int i, j;
	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &ele);

	fill_2d_array(arr, 4, ele);

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}


void fill_2d_array(int arr[][5], int row, int ele)
{
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < 5; j++)
			arr[i][j] = ele;
}