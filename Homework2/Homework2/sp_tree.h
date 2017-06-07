#pragma once
#define MAX_VERTEX 8 

int visited[MAX_VERTEX];
int adj[MAX_VERTEX][MAX_VERTEX] = { 0 }; //인접행렬
int st1[MAX_VERTEX] = { 0 }; //Spanning tree 간선의 시작정점
int st2[MAX_VERTEX] = { 0 }; //Spanning tree 간선의 끝정점
int counter = 0;
void sp_tree();
void dfs(int v);
void g_insert_edge(int v, int w); //graph간선 추가함수
void st_insert_edge(int v, int w); //Spanning tree간선 추가함수
