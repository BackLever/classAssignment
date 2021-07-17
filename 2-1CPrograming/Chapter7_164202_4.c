#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(void)
{
	int arr[SIZE];
	int i;
	int min = 0, max = 0;

	for (i = 0; i < SIZE; i++)
		arr[i] = rand() % 51;

	printf("배열: ");
	
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	for (i = 0; i < SIZE; i++)
		max = arr[max] > arr[i] ? max : i;
	for (i = 0; i < SIZE; i++)
		min = arr[min] < arr[i] ? min : i;

	printf("최대값: 인덱스=%d, 값=%d\n", max, arr[max]);
	printf("최소값: 인덱스=%d, 값=%d\n", min, arr[min]);

	return 0;
}