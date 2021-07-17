#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double get_area_of_square(double num);

int main(void)
{
	double r;
	printf("한 변의 길이? ");
	scanf(" %lf", &r);

	printf("정사각형의 면적: %f \n", get_area_of_square(r));
	return 0;
}

double get_area_of_square(double num)
{
	return num * num;
}