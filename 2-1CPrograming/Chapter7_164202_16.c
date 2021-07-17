# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int find_array(int arr[], int key);

int main(void)
{
	int i, key;
	int arr[10];

	for (i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}

	printf("\n찾을 값? ");
	scanf(" %d", &key);
	printf("%d는 %d번째 원소입니다.\n", key, find_array(arr, key));

	return 0;
}

int find_array(int arr[], int key)
{
	int i;

	for (i = 0; i < 10; i++)
		if (arr[i] == key)
		{
			return i;
			break;
		}
	if (i == 10)
		return -1;
}