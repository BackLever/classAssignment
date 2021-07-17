#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int get_perimeter(num1, num2);

int main(void)
{
	int a, b;
	printf("가로? ");
	scanf("%d", &a);
	printf("세로? ");
	scanf("%d", &b);

	printf("직사각형의 둘레: %d \n", get_perimeter(a, b));
	return 0;
}

int get_perimeter(num1, num2)
{
	return (num1 + num2) * 2;
}