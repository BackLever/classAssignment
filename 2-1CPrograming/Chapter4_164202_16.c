#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	unsigned char red, green, blue;
	int color=0;

	printf("red? ");
	scanf("%hhd", &red);
	color += red;

	printf("green? ");
	scanf("%hhd", &green);
	color += green << 8;

	printf("blue? ");
	scanf("%hhd", &blue);
	color += blue << 16;

	printf("RGB 트루컬러: %06X", color);
	return 0;
}