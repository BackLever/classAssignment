#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

int main(void)
{
	double a, b;
	
	printf("밑변? ");
	scanf("%lf", &a);
	printf("높이? ");
	scanf("%lf", &b);
	double c = sqrt(a * a + b * b);

	printf("빗변의 길이: %f", c);
	return 0;
}