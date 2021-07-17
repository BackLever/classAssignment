#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int discount_price(rate, price);

int main(void)
{
	int rate, price;

	printf("할인율(%%)? ");
	scanf("%d", &rate);

	while (1) {
		printf("제품의 가격? ");
		scanf("%d", &price);

		if (price == 0)
			break;

		printf("할인가: %d원 \n", discount_price(rate, price));
	}
	return 0;
}

int discount_price(rate, price)
{
	return price - rate * price / 100;
}