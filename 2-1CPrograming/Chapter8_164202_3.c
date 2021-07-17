#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
	int arr[10];
	int* p = arr;
	int i;

	srand((unsigned int)time(0));

	for (i = 0; i < 10; i++)
		arr[i] = rand() % 100;

	printf("배열: ");
	for (i=0;i<10;i++)
		printf("%2d ", p[i]);

	printf("\n역순: ");
	for (i = 0; i < 10; i++)
		printf("%2d ", p[9 - i]);

	return 0;
}