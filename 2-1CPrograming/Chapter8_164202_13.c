#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap_array(int arr1[], int arr2[]);

int main(void)
{
	int arr1[10], arr2[10];
	int i;

	srand((unsigned int)time(0));
	for (i = 0; i < 10; i++)
	{
		arr1[i] = rand() % 100;
		arr2[i] = rand() % 100;
	}

	printf("a: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr1[i]);
	printf("\n");
	
	printf("b: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr2[i]);
	printf("\n");

	swap_array(arr1, arr2);

	printf("<< swap_array 호출 후 >>\n");
	printf("a: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr1[i]);
	printf("\n");

	printf("b: ");
	for (i = 0; i < 10; i++)
		printf("%02d ", arr2[i]);
	printf("\n");

	return 0;
}

void swap_array(int arr1[], int arr2[])
{
	int temp[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		temp[i] = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp[i];
	}
}