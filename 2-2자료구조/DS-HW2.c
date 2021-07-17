#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_STACK_SIZE 300

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
void init_stack(StackType* s) { s->top = -1; }
int is_empty(StackType* s) { return (s->top == -1); }
int is_full(StackType* s) { return (s->top == (MAX_STACK_SIZE - 1)); }
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

typedef double element_d;
typedef struct {
	element_d data[MAX_STACK_SIZE];
	int top;
}StackType_d;
void init_stack_d(StackType_d* s) { s->top = -1; }
int is_empty_d(StackType_d* s) { return (s->top == -1); }
int is_full_d(StackType_d* s) { return (s->top == (MAX_STACK_SIZE - 1)); }
void push_d(StackType_d* s, element_d item) {
	if (is_full_d(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element_d pop_d(StackType_d* s) {
	if (is_empty_d(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element_d peek_d(StackType_d* s) {
	if (is_empty_d(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

void exp_check(char exp[])
{
	int i, count = 0, op_before = 0;
	int len = strlen(exp);
	char ch;

	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch) {
		case'u':
			op_before = 1;
			break;
		case'-':
			if (i == 0 || op_before == 1) {
				printf("허용되지 않는 수 표현입니다.\n");
				exit(1);
			}
			op_before = 1;
			break;
		case'+': case'*': case'/': case'^': case'.':
			if (i==0 || op_before == 1) {
				printf("계산이 불가능한 수식입니다.\n");
				exit(1);
			}
			op_before = 1;
			break;
		case '(':
			count++;
			op_before = 1;
			break;
		case ')':
			count--;
			if (count < 0) {
				printf("계산이 불가능한 수식입니다.\n");
				exit(1);
			}
			op_before = 0;
			break;
		default:
			op_before = 0;
			break;
		}
	}
	if (count != 0) {
		printf("계산이 불가능한 수식입니다.\n");
		exit(1);
	}
}

int prec(char op)
{
	switch (op) {
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': return 2;
	case'^': return 3;
	case'u': return 4;
	}
	return -1;
}

void infix_to_postfix(char exp[], char tmp[])
{
	int i, space = 0, j = -1;
	int len = strlen(exp);
	int czero = 0, adot = 0;
	char ch, top_op;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case'+': case'-': case'*': case'/': case'^': case'u':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
			{
				tmp[++j] = ' ';
				tmp[++j] = peek(&s);
				printf(" %c", pop(&s));
			}
			push(&s, ch);
			space = 1;
			czero = 0;
			adot = 0;
			break;
		case'(':
			push(&s, ch);
			break;
		case')':
			top_op = pop(&s);
			while (top_op != '(') {
				tmp[++j] = ' ';
				tmp[++j] = top_op;
				printf(" %c", top_op);
				top_op = pop(&s);
			}
			space = 1;
			break;
		case'.':
			adot = 1;
		case'0':
			if (czero == 0 && adot == 0 && exp[i + 1] != '.')
				break;
		default:
			if (space == 0) {
				tmp[++j] = ch;
				printf("%c", ch);
			}
			else if (space == 1) {
				tmp[++j] = ' ';
				tmp[++j] = ch;
				printf(" %c", ch);
				space = 0;
			}
			czero = 1;
			break;
		}
	}
	while (!is_empty(&s)) {
		tmp[++j] = ' ';
		tmp[++j] = peek(&s);
		printf(" %c", pop(&s));
	}
	printf("\n");
	tmp[++j] = '\0';
}

double get_decimal(double num, int i)
{
	if (i == 0)
		return num;
	return get_decimal(num, i - 1) / 10.0;
}

double eval(char exp[])
{
	double op1, op2, value;
	int tmpval, i = 0;
	int len = strlen(exp);
	int is_int = 0, is_dot = 0;
	int decimal_count = 0;
	char ch;
	StackType_d sd;
	init_stack_d(&sd);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch == ' ') {
			is_int = 0;
			is_dot = 0;
			decimal_count = 0;
		}
		else if (ch == '.') {
			is_dot = 1;
		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^' && ch != 'u') {
			tmpval = ch - '0';
			value = tmpval;
			if (is_int == 1) {
				if (is_dot == 0) {
					op1 = pop_d(&sd) * 10 + value;
				}
				else if (is_dot == 1) {
					decimal_count++;
					op1 = pop_d(&sd) + get_decimal(value, decimal_count);
				}
				value = op1;
			}
			push_d(&sd, value);
			is_int = 1;
		}
		else if (ch == 'u') {
			op1 = pop_d(&sd);
			push_d(&sd, -op1);
			is_int = 0;
		}
		else {
			op2 = pop_d(&sd);
			op1 = pop_d(&sd);
			is_int = 0;
			switch (ch) {
			case'+': push_d(&sd, op1 + op2); break;
			case'-': push_d(&sd, op1 - op2); break;
			case'*': push_d(&sd, op1 * op2); break;
			case'/': push_d(&sd, op1 / op2); break;
			case'^': push_d(&sd, pow(op1, op2)); break;
			}
		}
	}
	return pop_d(&sd);
}

int main(void)
{
	char arr[256];
	char* p = arr;
	char tmparr[256];
	char* tp = tmparr;

	printf("infix: ");
	gets_s(arr, sizeof(arr));

	exp_check(p);

	printf("postfix: ");
	infix_to_postfix(p, tp);
	printf("결과값: %g\n", eval(tp));

	return 0;
}