#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	FILE* fpr = NULL;
	FILE* fpw = NULL;
	char* p1 = NULL;
	char* p2 = NULL;
	char fname[128];
	char fbname[128];
	char str[BUFSIZ];

	printf("내용을 뒤집을 파일? ");	//	e:\2-1\cprogramming\codes\교가.txt
	gets_s(fname, sizeof(fname));

	fpr = fopen(fname, "r");
	if (fpr == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	p2 = fgets(str, sizeof(str), fpr);
	p1 = strtok(fname, ".");
	strcpy(fbname, p1);
	strcat(fbname, "back_164202.txt");

	fpw = fopen(fbname, "w");
	if (fpw == NULL)
	{
		printf("파일 저장 실패\n");
		fclose(fpr);
		return 1;
	}
	
	p2 = strchr(p2, '\0');
	p2--;
	while (p2 > str)
	{
		if (0 <= *p2 && *p2 <= 127)
		{
			fprintf(fpw, "%c", *p2);
			p2--;
		}
		else
		{
			fprintf(fpw, "%c%c", *(p2 - 1), *p2);
			p2 -= 2;
		}
	}

	printf("%s을 생성했습니다.\n", fbname);

	fclose(fpw);
	fclose(fpr);
	return 0;
}