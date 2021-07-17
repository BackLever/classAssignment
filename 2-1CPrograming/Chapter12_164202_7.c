#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct menu {
	char name[20];
	int price;
}MENU;

int main(void)
{
	MENU arr[6] = {
		{"아메리카노" , 4000}, {"카페라떼", 4500},
		{"멜론스무디", 4500}, {"딸기스무디", 4500},
		{"우유", 3000}, {"콜라", 2500}
	};
	FILE* fp = fopen("e:\\2-1\\cprogramming\\codes\\12_7_receipt.txt", "w");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	int order[6];
	int i, total;

	printf("[메뉴]");
	for (i = 0; i < 6; i++)
	{
		if (i % 3 == 0)
			printf("\n");
		printf("%-10s:%-4d", arr[i].name, arr[i].price);
		if (i != 5)
			printf(", ");
	}
	printf("\n");

	while (1) {
		total = 0;
		for (i = 0; i < 6; i++)
		{
			printf("%-10s 수량? ", arr[i].name);
			scanf("%d", &order[i]);
			total += arr[i].price * order[i];
		}
		if (total == 0)
			break;

		printf("결제 금액: %d\n\n", total);
		fprintf(fp, "%-12s\t%-6s%-6s%-6s\n", "제품명", "단가", "수량", "금액");
		fputs("------------------------------------------\n", fp);
		for (i = 0; i < 6; i++)
		{
			if (order[i] != 0)
				fprintf(fp, "%-12s\t %-4d %3d %6d\n", arr[i].name, arr[i].price, order[i], arr[i].price * order[i]);
		}
		fputs("------------------------------------------\n", fp);
		fprintf(fp, "%-36s% -6d\n\n", "합계", total);
	}

	fclose(fp);

	return 0;
}