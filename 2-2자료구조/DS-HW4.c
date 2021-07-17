#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
} TreeNode;

TreeNode* create(void)
{
	TreeNode* node = NULL;
	return node;
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

int get_count(TreeNode* node) {
	if (!node)
		return 0;
	else
		return get_count(node->left) + get_count(node->right) + 1;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	
	return node;
}

bool is_empty(TreeNode* node)
{
	if (node == NULL)
		return true;
	else
		return false;
}

TreeNode* add(TreeNode* node)
{
	int item;
	while (1)
	{
		scanf("%d", &item);
		if (item == 0)
			return node;
		getchar();

		node = insert_node(node, item);
	}
}

bool search(TreeNode* node, int key)
{
	if (node == NULL) return false;
	if (key == node->key) return true;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

static int index = 0;
int* get_item2(TreeNode* node, int* arr)
{
	arr[index] = node->key;
	if (node->left) {
		index++;
		arr = get_item2(node->left, arr);
	}
	if (node->right) {
		index++;
		arr = get_item2(node->right, arr);
	}
	return arr;
}

TreeNode* union_set(TreeNode* nodeA, TreeNode* nodeB)
{
	TreeNode* setC = create();

	int* arrA = malloc(sizeof(int) * get_count(nodeA));
	index = 0;
	arrA = get_item2(nodeA, arrA);
	int* arrB = malloc(sizeof(int) * get_count(nodeB));
	index = 0;
	arrB = get_item2(nodeB, arrB);

	for (int i = 0; i < get_count(nodeA); i++)
		setC = insert_node(setC, arrA[i]);

	for (int i = 0; i < get_count(nodeB); i++)
		setC = insert_node(setC, arrB[i]);
	
	free(arrA);
	free(arrB);
	return setC;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* node, int key)
{
	if (node == NULL) return node;

	if (key < node->key)
		node->left = delete_node(node->left, key);
	else if (key > node->key)
		node->right = delete_node(node->right, key);
	else {
		if (node->left == NULL) {
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}

		TreeNode* temp = min_value_node(node->right);
		node->key = temp->key;
		node->right = delete_node(node->right, temp->key);
	}
	return node;
}

TreeNode* difference(TreeNode* nodeA, TreeNode* nodeB)
{
	TreeNode* setD = create();

	int* arrA = malloc(sizeof(int) * get_count(nodeA));
	index = 0;
	arrA = get_item2(nodeA, arrA);
	int* arrB = malloc(sizeof(int) * get_count(nodeB));
	index = 0;
	arrB = get_item2(nodeB, arrB);

	for (int i = 0; i < get_count(nodeA); i++)
		setD = insert_node(setD, arrA[i]);

	for (int i = 0; i < get_count(nodeB); i++)
		setD = delete_node(setD, arrB[i]);

	free(arrA);
	free(arrB);
	return setD;
}

int level_sum(TreeNode* node, int level)
{
	if (!node)
		return 0;
	else if (level == 1)
		return node->key;
	return level_sum(node->left, level - 1) + level_sum(node->right, level - 1);
}

void preorder_traverse(TreeNode* node)
{
	if (node) {
		printf("[%d] ", node->key);
		preorder_traverse(node->left);
		preorder_traverse(node->right);
	}
}

void inorder_nth(TreeNode* node, int nth)
{
	if (node) {
		inorder_nth(node->left, nth);
		index++;
		if (index == nth)
			printf("[%d]", node->key);
		inorder_nth(node->right, nth);
	}
}

int main(void)
{
	TreeNode* setA = create();
	TreeNode* setB = create();

	printf("Add to setA: ");
	setA = add(setA);
	printf("Add to setB: ");
	setB = add(setB);

	TreeNode* setC = union_set(setA, setB);
	TreeNode* setD = difference(setA, setB);

	printf("\n");
	if (search(setA, 10))
		printf("setA에 10이 있습니다.\n");
	else
		printf("setA에 10이 없습니다.\n");

	printf("\n");
	printf("preorderA: ");
	preorder_traverse(setA);
	printf("\n");
	printf("preorderB: ");
	preorder_traverse(setB);
	printf("\n");
	printf("preorderC: ");
	preorder_traverse(setC);
	printf("\n");
	printf("preorderD: ");
	preorder_traverse(setD);
	printf("\n");

	printf("\n");
	if (is_empty(difference(setC, setD)))
		printf("setC와 setD의 차집합은 공집합입니다.\n");
	else
		printf("setC와 setD의 차집합은 공집합이 아닙니다.\n");

	printf("setC의 3-level에서 level sum: %d\n", level_sum(setC, 3));

	index = 0;
	printf("setC의 Inorder 5th: ");
	inorder_nth(setC, 5);
	printf("\n");

	return 0;
}