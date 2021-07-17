#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct product {
	char name[20];
	int price;
	int stock;
}PRODUCT;

void print_product(PRODUCT* stuff);

int main(void)
{
	PRODUCT prd1;

	printf("제품명? ");
	scanf("%s", prd1.name);
	printf("가격? ");
	scanf("%d", &prd1.price);
	printf("재고? ");
	scanf("%d", &prd1.stock);

	print_product(&prd1);

	return 0;
}

void print_product(PRODUCT* stuff)
{
	printf("[%s %d원 재고:%d]\n", stuff->name, stuff->price, stuff->stock);
}