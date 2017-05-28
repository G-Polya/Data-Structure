#include <stdio.h>
#include "adj_list.h"

void insert_edge(int v, int w) 
{
	nodeptr nNode1 = (nodeptr)malloc(sizeof(node));
	nodeptr nNode2 = (nodeptr)malloc(sizeof(node));

	nNode1->vertex = w;
	nNode1->link = adj[v];
	adj[v] = nNode1;

	nNode2->vertex = v;
	nNode2->link = adj[w];
	adj[w] = nNode2;
}

void build_simple_graph()
{
	int graph[][6] = { { 1,2 },{ 1,3 },{ 1,4 },{ 2,5 },{ 3,5 },{ 4,5 } };
	int nEdge = 0, nVertex = 0, i;

	for (i = 0; i < MAX_VERTICES; i++) {
		adj[i] = NULL;
	}

	for (i = 0; i < 6; i++) {
		insert_edge(graph[i][0], graph[i][1]);
		nEdge++;
	}

	for (i = 0; i < MAX_VERTICES; i++) {
		if (adj[i] != NULL) { nVertex++; }
	}

	printf("GRAPH IS BUILT. V = %d, E = %d\n\n", nEdge, nVertex);

}

void DFS(int v) 
{
	nodeptr point = adj[v];
	printf("%d ", v);
	visited[v] = 1;

	while (point != NULL) {
		if (visited[point->vertex] == 0) {
			DFS(point->vertex);
		}
		point = point->link;
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
	int index;
	nodeptr point;

	queue = (nodeptr)malloc(sizeof(node));
	queue->link = NULL;

	addq(v);
	visited[v] = 1;
	printf("%d ", v);

	while (queue->link != NULL)
	{
		index = deleteq();
		point = adj[index];
		while (point != NULL)
		{
			if (visited[point->vertex] == 0)
			{
				addq(point->vertex);
				visited[point->vertex] = 1;
				printf("%d ", point->vertex);
			}
			point = point->link;
		}
	}
}