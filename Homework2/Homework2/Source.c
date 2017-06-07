#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sp_tree.h"
#include <stdbool.h>



void g_insert_edge(int v, int w)
{
	adj[v][w] = 1;
	adj[w][v] = 1;
}

void st_insert_edge(int v, int w)
{
	int temp;

	if (v<w)
	{
		st1[counter] = v; st2[counter] = w;
	}
	else
	{
		st1[counter] = w; st2[counter] = v;
	}
	counter++;
}

void sp_tree()
{
	int v, w, i;
	FILE *file;

	file = fopen("input.txt", "r");
	while (fscanf(file, "%d, %d", &v, &w) == 2)
		g_insert_edge(v, w); //graph간선을 insert한다
	fclose(file);
	dfs(1); //1번 정점부터 dfs를 수행하면서 Spanning tree를 찾는다
	file = fopen("output.txt", "w");
	for (i = 0; i<counter; i++)
		fprintf(file, "%d, %d\n", st1[i], st2[i]);
	fclose(file);
}

void dfs(int v)
{
	int i;

	visited[v] = true;
	for (i = 1; i <= MAX_VERTEX; i++)
	{
		if (!visited[i] && adj[v][i])
		{
			st_insert_edge(v, i);  //Spanning tree간선을 insert한다
			dfs(i);
		}
	}
}