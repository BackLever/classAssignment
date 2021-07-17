#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isvalid(char id[]);

int main(void)
{
	char id[100];
	int k;

	do {
		printf("ID? ");
		gets_s(id, sizeof(id));
		k = isvalid(id);
	} while (k != 1);
}

int isvalid(char id[])
{
	unsigned int i;
	for (i = 0; i < strlen(id); i++)
		if (isalnum(id[i]) == 0) {
			printf("ID는 영문자와 숫자로만 구성될 수 있습니다.\n");
			return 0;
		}
	if (strlen(id) < 8) {
		printf("ID는 8자 이상이어야 합니다.\n");
		return 0;
	}
	if (isalpha(id[0]) == 0) {
		printf("ID는 영문자로 시작해야 합니다.\n");
		return 0;
	}
	printf("%s는 ID로 사용할 수 있습니다.\n", id);
	return 1;
}