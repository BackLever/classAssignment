#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int electric_charge(usage);

int main(void)
{
	int usage;
	while (1)
	{
		printf("월 사용량(kWh)? ");
		scanf("%d", &usage);
		if (usage == -1)
			break;
		printf("전기요금: %6d원\n", electric_charge(usage));
	}
	return 0;
}

int electric_charge(usage)
{
	double charge;
	if (usage <= 200)
		charge = 910 + 93.3 * usage;
	else if (usage > 400)
		charge = 7300 + 93.3 * 200 + 187.9 * 200 + 280.6 * (usage - 400);
	else
		charge = 1600 + 93.3 * 200 + 187.9 * (usage - 200);
	return charge;
}