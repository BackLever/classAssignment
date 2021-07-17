#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort_array(int arr[]);

int main(void)
{
	int arr[10];
	int i;

	srand((unsigned int)time(0));
	for (i = 0; i < 10; i++)
		arr[i] = rand() % 100;

	printf("정렬 전: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr[i]);
	printf("\n");

	sort_array(arr);

	printf("정렬 후: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr[i]);
	printf("\n");

	return 0;
}


void sort_array(int arr[])
{
	int i, j, temp;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}
