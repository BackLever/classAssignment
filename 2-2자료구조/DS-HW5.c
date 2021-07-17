#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];
int count = 0;

void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void delete_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}

void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void dfs_mat(GraphType* g, int v)
{
	int w;
	visited[v] = TRUE;
	count++;
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}

GraphType* copy(GraphType* g)
{
	GraphType* temp;
	temp = (GraphType*)malloc(sizeof(GraphType));
	init(temp);
	temp->n = g->n;
	for (int i = 0; i < temp->n; i++)
		for (int j = 0; j < temp->n; j++)
			if (g->adj_mat[i][j] == 1)
				temp->adj_mat[i][j] = 1;
	return temp;
}

void find_bridge(GraphType* g)
{
	GraphType* temp = copy(g);
	for (int i = 0; i < temp->n; i++) {
		for (int j = i; j < temp->n; j++) {
			if (temp->adj_mat[i][j] == 1) {
				delete_edge(temp, i, j);
				count = 0;
				dfs_mat(temp, 0);
				for (int k = 0; k < MAX_VERTICES; k++)
					visited[k] = FALSE;
				if (count != temp->n)
					printf("브릿지: %d - %d\n", i, j);
				insert_edge(temp, i, j);
			}
		}
	}
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 10; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 6);
	insert_edge(g, 5, 7);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);

	print_adj_mat(g);
	printf("\n");
	find_bridge(g);

	return 0;
}