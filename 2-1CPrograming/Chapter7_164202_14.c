#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int list[10];
	int i, temp, ran = -1;

	srand((unsigned int)time(0));

	for (i = 0; i < 10; i++)
		list[i] = rand() % 100;

	printf("셔플 전: ");
	for (i = 0; i < 10; i++)
		printf(" %2d", list[i]);
	printf("\n");

	for (i = 0; i < 9; i++)
	{
		temp = list[i];
		while (ran < i)
			ran = rand() % 10;

		list[i] = list[ran];
		list[ran] = temp;
		ran = -1;
	}

	printf("셔플 후: ");
	for (i = 0; i < 10; i++)
		printf(" %2d", list[i]);
	printf("\n");

	return 0;
}