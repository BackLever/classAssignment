#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* join_string(char* str1, char* str2);

int main(void)
{
	char str1[100];
	char str2[100];

	printf("첫 번째 문자열? ");
	gets_s(str1, sizeof(str1));

	printf("두 번째 문자열? ");
	gets_s(str2, sizeof(str2));

	printf("%s\n", join_string(str1, str2));

	return 0;
}

char* join_string(char* str1, char* str2)
{
	char* str3 = NULL;
	str3 = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2)));
	if (str3 == NULL)
	{
		printf("동적 메모리 할당 실패\n");
		return NULL;
	}
	strcpy(str3, str1);
	strcat(str3, str2);

	return str3;
}