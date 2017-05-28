#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "adj_list.h"

int main() {
	char c;
	int i, v;

	build_simple_graph();

	printf("********** COMMAND ***********\n");
	printf("D : DFS, B : BFS, Q : QUIT\n");
	printf("******************************\n");

	while (1) {
		printf("\nCOMMAND >>");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c) {
		case 'D':
			printf("\n START VERTEX : ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) { visited[i] = 0; }
			DFS(v);
			printf("\n");
			break;
		case 'B':
			printf("\n START VERTEX : ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) { visited[i] = 0; }
			BFS(v);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		}
	}
}