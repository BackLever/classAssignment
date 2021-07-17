#include<stdio.h>
#include<stdlib.h>

int compare_str(const void* e1, const void* e2);
void print_array(char arr[][30], int size);

int main(void)
{
	char arr[5][30] = {
		"Inception",
		"Leon",
		"Wish",
		"About time",
		"Accountant"
	};

	puts("<< 정렬 전 >>");
	print_array(arr, 5);

	qsort(arr, 5, sizeof(arr[0]), compare_str);

	puts("<< 정렬 후 >>");
	print_array(arr, 5);

	return 0;
}

int compare_str(const void* e1, const void* e2)
{
	const char* p1 = (const char*)e1;
	const char* p2 = (const char*)e2;
	return (*p1 - *p2);
}

void print_array(char arr[][30], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}