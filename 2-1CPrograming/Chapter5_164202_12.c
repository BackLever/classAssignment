#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int i;
	double money, rate, a;
	printf("원금? ");
	scanf("%lf", &money);
	printf("연이율(%%)? ");
	scanf("%lf", &rate);
	
	for (i = 0; i < 10; i++)
	{
		a = money * rate / 100;
		printf("%2d년째 이자: %.2f, 원리합계: %.2f \n", i + 1, a, money + a);
		money += a;
	}
	return 0;
}