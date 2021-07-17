#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int price[5];
	int dis, i;

	printf("상품가 5개를 입력하세요: \n");
	for (i = 0; i < 5; i++)
		scanf(" %d", &price[i]);

	printf("할인율(%%)? ");
	scanf(" %d", &dis);

	for (i = 0; i < 5; i++)
		printf("가격: %6d --> 할인가: %6d\n", price[i], price[i] * dis / 100);

	return 0;
}