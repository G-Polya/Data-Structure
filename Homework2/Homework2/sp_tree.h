#pragma once
#define MAX_VERTEX 8 

int visited[MAX_VERTEX];
int adj[MAX_VERTEX][MAX_VERTEX] = { 0 }; //�������
int st1[MAX_VERTEX] = { 0 }; //Spanning tree ������ ��������
int st2[MAX_VERTEX] = { 0 }; //Spanning tree ������ ������
int counter = 0;
void sp_tree();
void dfs(int v);
void g_insert_edge(int v, int w); //graph���� �߰��Լ�
void st_insert_edge(int v, int w); //Spanning tree���� �߰��Լ�
