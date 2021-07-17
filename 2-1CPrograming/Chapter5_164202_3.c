#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int change;
	int num;

	printf("거스름돈? ");
	scanf("%d", &change);
	change /= 10;
	change *= 10;

	printf("거스름돈 (10원미만 절사): %d \n", change);
	if (change >= 50000) {
		printf("  50000원 %d장 \n", change / 50000);
		change -= change / 50000 * 50000;
	}
	if (change >= 10000) {
		printf("  10000원 %d장 \n", change / 10000);
		change -= change / 10000 * 10000;
	}
	if (change >= 5000) {
		printf("   5000원 %d장 \n", change / 5000);
		change -= change / 5000 * 5000;
	}
	if (change >= 1000) {
		printf("   1000원 %d장 \n", change / 1000);
		change -= change / 1000 * 1000;
	}
	if (change >= 500) {
		printf("    500원 %d개 \n", change / 500);
		change -= change / 500 * 500;
	}
	if (change >= 100) {
		printf("    100원 %d개 \n", change / 100);
		change -= change / 100 * 100;
	}
	if (change >= 50) {
		printf("     50원 %d개 \n", change / 50);
		change -= change / 50 * 50;
	}
	if (change >= 10) {
		printf("     10원 %d개 \n", change / 10);
	}
	return 0;
}