#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int get_max_num(int* arr, int len);

int main(void)
{
	int num, i;
	printf("리스트의 원소 수? ");
	scanf("%d", &num);

	int* arr = malloc(sizeof(int) * num);
	srand((unsigned int)time(0));
	for (i = 0; i < num; i++)
		arr[i] = rand() % 100;

	printf("[%d", arr[0]);
	for (i = 1; i < num; i++)
		printf(", %d", arr[i]);
	printf("] 에서 최댓값은?\n");

	printf("%d 입니다.\n", get_max_num(arr, num));

	return 0;
}

int get_max_num(int* arr, int len)
{
	int fnum;

	if (len == 1)
		return arr[0];
	else
	{
		fnum = arr[0];
		arr++;
		len--;
		return fnum > get_max_num(arr, len) ? fnum : get_max_num(arr, len);
	}
}
