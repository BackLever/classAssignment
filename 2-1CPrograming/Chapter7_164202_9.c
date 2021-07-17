#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int arr[12];
	int i, j;

	for (i = 0; i < 12; i++)
		arr[i] = 20000 + rand() % 79 * 1000;

	for (i = 0; i < 12; i++)
	{
		printf("%2d월 %6d: ", i+1, arr[i]);
		for (j = 0; j < arr[i] / 2000; j++)
			printf("*");
		printf("\n");
	}
}