#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int pay, bep, gua, i;
	printf("기본 출연료? ");
	scanf("%d", &pay);
	printf("손익 분기점 관객 수? ");
	scanf("%d", &bep);
	printf("관객 1인당 러닝 개런티? ");
	scanf("%d", &gua);

	for (i = 1; i <= 15; i++)
		if (i * 1000000 <= bep)
			printf("관객 %8d명 일 때 예상 출연료: % 10d \n", i * 1000000, pay);
		else
			printf("관객 %8d명 일 때 예상 출연료: %10d \n", i * 1000000, pay + (i * 1000000 - bep) * gua);
	return 0;
}
