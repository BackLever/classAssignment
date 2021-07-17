#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int numA, numB;
	double numC;

	printf("용매(g)? ");
	scanf("%d", &numA);
	printf("용질(g)? ");
	scanf("%d", &numB);
	numC = (double)numB / (numA + numB) * 100;

	printf("농도: %.2f %%", numC);
	return 0;
}