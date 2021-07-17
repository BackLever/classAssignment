#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct login {
	char id[20];
	char pw[20];
}LOGIN;

int main(void)
{
	LOGIN arr[] = {
		{"jindol", "001007"},
		{"superman", "kryp009"},
		{"specialist00", "spe@@33"}
	};
	LOGIN att;
	int i;
	int sz = sizeof(arr) / sizeof(arr[0]);

	while (1) {
		printf("ID? ");
		gets_s(att.id, sizeof(att.id));

		if (strcmp(att.id, ".") == 0)
			break;

		for (i = 0; i < sz; i++)
		{
			if (strcmp(att.id, arr[i].id) == 0)
			{
				printf("PW: ");
				gets_s(att.pw, sizeof(att.pw));
				if (strcmp(att.pw, arr[i].pw) == 0)
				{
					printf("로그인 성공\n");
					break;
				}
				printf("로그인 실패\n");
				break;
			}
		}
		if (i == sz)
			printf("ID가 없습니다.\n");
	}
	return 0;
}