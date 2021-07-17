#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_prime(int num);

int main(void)
{
	int num, i, a;
	int j = 0;

	printf("1~N사이의 소수를 구합니다. N은? ");
	scanf("%d", &num);

	for (i = 2; i < num; i++)
	{
		a = is_prime(i);
		if (a != 0)
		{
			printf("%3d ", a);
			j++;
			if (j % 10 == 0)
				printf("\n");
		}
	}
	printf("\n소수는 모두 %d개 입니다.", j);
	return 0;
}

int is_prime(int num)
{
	int i;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
		if (num == i - 1)
			return num;
	}
}