#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int sum_of_digits(int num, int sum);

int main(void)
{
	int num, sum = 0;

	while (1)
	{
		printf("정수? ");
		scanf("%d", &num);

		if (num == 0)
			break;

		printf("sum of digits: %d\n", sum_of_digits(num, sum));
	}

	return 0;
}

int sum_of_digits(int num, int sum)
{
	if (num == 0)
		return sum;
	sum += num % 10;
	return sum_of_digits(num / 10, sum);
}