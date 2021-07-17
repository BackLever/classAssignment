#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 10

void get_min_max(int arr[], int *min, int *max);

int main(void)
{
	int arr[SIZE];
	int* p = arr;
	int max, min;
	int i;

	srand((unsigned int)time(0));
	for (i = 0; i < SIZE; i++)
		arr[i] = rand() % 100;

	printf("배열: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", p[i]);
	printf("\n");

	get_min_max(p, &min, &max);

	printf("최대값: %d\n", max);
	printf("최소값: %d\n", min);

	return 0;
}

void get_min_max(int arr[], int* min, int* max)
{
	int i;
	*max = arr[0], *min = arr[0];

	for (i = 0; i < SIZE; i++)
	{
		*max = *max > arr[i] ? *max : arr[i];
		*min = *min < arr[i] ? *min : arr[i];
	}
}