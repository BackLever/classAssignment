#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct element {
	int value;
	struct element* link;
} element;

element* create()
{
	element* p = NULL;
	return p;
}

bool is_empty(element* head)
{
	element* p = head;
	if (p == NULL)
		return true;
	else
		return false;
}

bool search(element* head, int value)
{
	element* p = head;
	while (p != NULL) {
		if (p->value == value) return true;
		p = p->link;
	}
	return false;
}

element* insert_first(element* head, int value)
{
	element* temp = (element*)malloc(sizeof(element));
	temp->value = value;
	temp->link = head;
	head = temp;
	return head;
}

element* add(element* head)
{
	int value;
	while(1)
	{
		scanf("%d", &value);
		getchar();
		if (value == 0)
			break;
		if (search(head, value))
			continue;
		head = insert_first(head, value);
	}
	return head;
}

element* unionSet(element* headA, element* headB)
{
	element* head = create();
	element* ap = headA; 
	element* bp = headB;

	while (ap != NULL) {
		head = insert_first(head, ap->value);
		ap = ap->link;
	}

	while (bp != NULL) {
		if (!search(head, bp->value))
			head = insert_first(head, bp->value);
		bp = bp->link;
	}

	return head;
}

element* difference(element* headA, element* headB)
{
	element* head = create();
	element* ap = headA;
	element* bp = headB;

	while (ap != NULL) {
		if (!search(bp, ap->value))
			head = insert_first(head, ap->value);
		ap = ap->link;
	}

	return head;
}

void display(element* head)
{
	element* p = head;
	if (is_empty(p)) {
		printf("(  )\n");
		return;
	}
	printf("( %d", p->value);
	p = p->link;
	for (; p != NULL; p = p->link)
		printf(", %d", p->value);
	printf(" )\n");
}

int main(void)
{
	element* head_A = create();
	element* head_B = create();

	printf("Add element to set A(Enter 0 on completion): ");
	head_A = add(head_A);
	printf("Add element to set B(Enter 0 on completion): ");
	head_B = add(head_B);

	element* head_C = unionSet(head_A, head_B);
	element* head_D = difference(head_A, head_B);

	printf("\n");
	printf("set A list: ");
	display(head_A);
	printf("set B list: ");
	display(head_B);
	printf("set C(A+B) list: ");
	display(head_C);
	printf("set D(A-B) list: ");
	display(head_D);
	
	printf("\n");
	if (search(head_A, 10))
		printf("집합 A에 원소 10이 존재합니다.\n");
	else
		printf("집합 A에 원소 10이 없습니다.\n");

	printf("\n");
	printf("set C-D list: ");
	display(difference(head_C, head_D));
	if (is_empty(difference(head_C, head_D)))
		printf("집합 C와 집합 D의 차집합은 공집합입니다.\n");
	else
		printf("집합 C와 집합 D의 차집합은 공집합이 아닙니다.\n");

	return 0;
}