#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_dictionary.h"
void main()
{
	char c, fname[20];
	char w1[100], *w2;
	int wcount;
	printf("************* Command ************\n");
	printf("R: Read data, S: Search data \n");
	printf("P: Print inorder, Q: Quit \n");
	printf("**********************************\n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", w1);
			w2 = bst_search(w1);
			if (w2) printf(" Meaning: %s \n", w2);
			else printf(" No such word ! \n");
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

void bst_initialize()
{
	root = (tree_pointer)malloc(sizeof(tree_node));

	root->left = NULL;

	root->right = NULL;

	strcpy(root->w1, "DanceDance");

	strcpy(root->w2, "DanceDance");

	return;
}

void bst_insert(char* w1, char* w2)
{
	tree_pointer p = root;
	tree_pointer newNode = (tree_pointer)malloc(sizeof(tree_node));

	int compare;

	newNode->left = NULL;
	newNode->right = NULL;

	strcpy(newNode->w1, w1);
	strcpy(newNode->w2, w2);

	while (1)
	{
		compare = strcmp(p->w1, newNode->w1);
		if (compare < 0)
		{
			if (p->right == NULL)
			{
				p->right = newNode;
				break;

			}
			else
				p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				p->left = newNode;
				break;
			}
			else
			{
				p = p->left;
			}
			return;
		}
	}
}

int build_dictionary(char *fname)
{
	char w1[100], w2[100];

	FILE *fp = fopen(fname, "r");
	int count = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%s %s", w1, w2);
		bst_insert(w1, w2);
		count++;
	}
	fclose(fname);

	return count;
}

char* bst_search(char* w1)
{
	tree_pointer p = root;
	int compare;

	char* result = NULL;

	while (1)
	{
		compare = strcmp(p->w1, w1);
		if (compare < 0)
		{
			if (p->right == NULL)
				break;
			else
				p = p->left;
		}
		else if (compare > 0)
		{
			if (p->left == NULL)
				break;
			else
				p = p->left;
		}
		else
		{
			result = p->w2;
			break;
		}
	}
	return result;
}

void bst_show_inorder(tree_pointer p)
{
	if (p != NULL)
	{
		bst_show_inorder(p->left);
		if (p != root)
		{
			printf(" %s %s\n", p->w1, p->w2);
		}
		bst_show_inorder(p->right);
	}

	return;
}