#include <stdio.h>
#include "adj_matrix.h"

void insert_edge(int v, int w) 
{
	adj[v][w] = 1;
	adj[w][v] = 1;
}

void build_simple_graph() 
{
	int graph[][6] = { { 1,2 },{ 1,3 },{ 1,4 },{ 2,5 },{ 3,5 },{ 4,5 } };
	int nEdge = 0, nVertex = 0, i, j;

	for (i = 0; i < MAX_VERTICES; i++) 
	{
		for (j = 0; j < MAX_VERTICES; j++)
			adj[i][j] = 0;
	}

	for (i = 0; i < 6; i++)
	{
		insert_edge(graph[i][0], graph[i][1]);
		nEdge++;

		if (nVertex < graph[i][0]) { nVertex = graph[i][0]; }
		if (nVertex < graph[i][1]) { nVertex = graph[i][1]; }
	}

	printf("GRAPH IS BUILT. V = %d, E = %d\n\n", nEdge, nVertex);
}

void DFS(int v) 
{
	int i;
	nodeptr point = adj[v];
	printf("%d ", v);
	visited[v] = 1;

	for (i = 1; i <= 5; i++)
	{
		if (visited[i] == 0 && adj[v][i] == 1) {
			DFS(i);
		}
	}
}

void addq(int e)
{
	nodeptr point = queue;

	nodeptr nNode = (nodeptr)malloc(sizeof(node));
	nNode->link = NULL;
	nNode->vertex = e;

	while (point->link != NULL) { point = point->link; }

	point->link = nNode;
}

int deleteq() 
{
	int result = queue->link->vertex;
	nodeptr dNode = queue;

	queue = queue->link;
	free(dNode);

	return result;
}

void BFS(int v) 
{
	int index, i;
	nodeptr point;

	queue = (nodeptr)malloc(sizeof(node));
	queue->link = NULL;

	addq(v);
	visited[v] = 1;
	printf("%d ", v);

	while (queue->link != NULL)
	{
		index = deleteq();
		for (i = 1; i <= 5; i++)
		{
			if (visited[i] == 0 && adj[index][i] == 1) 
			{
				addq(i);
				visited[i] = 1;
				printf("%d ", i);
			}
		}
	}
}