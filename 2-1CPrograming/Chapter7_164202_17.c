#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int arr[10];
	int i, j;

	for (i = 0; i < 10; i++) {
		printf("배열에 추가할 원소? ");
		scanf("%d", &arr[i]);

		for (j = 0; j < i + 1; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
	return 0;
}
