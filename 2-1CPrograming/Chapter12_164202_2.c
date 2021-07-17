//한글 깨짐
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main(void)
{
	_wsetlocale(LC_ALL, L"korean");

	char fname[128];
	FILE* fp = NULL;
	char ch;

	printf("파일명? ");
	gets_s(fname, sizeof(fname));

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("%s 파일 열기 실패\n", fname);
		return 1;
	}
	while ((ch = fgetc(fp)) != EOF)
	{
		if (isalpha(ch))
			ch = tolower(ch);
		fputc(ch, stdout);
	}
	fclose(fp);

	return 0;
}