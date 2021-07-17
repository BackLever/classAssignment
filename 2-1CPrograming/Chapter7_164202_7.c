#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void fill_array(int arr[], int size, int num);

int main(void)
{
	int arr[10];
	int num, i;

	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &num);

	fill_array(arr, 10, num);

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}

void fill_array(int arr[], int size, int num)
{
	int i;

	for (i = 0; i < size; i++)
		arr[i] = num;
}