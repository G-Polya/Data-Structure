#include <stdio.h>
#include "binary_tree.h"
#include <math.h>
#include <stdlib.h>
#define log(x, base) log(x) / log(base)			//base를 밑으로하는 log, x는 진수

void main()
{
	char c;
	int n;
	tree_pointer t;
	t = build_simple_tree();
	printf("************* Command ************\n");
	printf("C: Count tree, A: Sum tree data \n");
	printf("H: Height of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit \n");
	printf("**********************************\n");
	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_sum(t);
			printf("\n Sum of tree data = %d \n", n);
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			bt_free(t);
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

tree_pointer build_simple_tree()
{
	tree_pointer n1 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n2 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n3 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n4 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n5 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n6 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n7 = (tree_pointer)malloc(sizeof(tree_node));
	//tree_pointer n8 = (tree_pointer)malloc(sizeof(tree_node));
	//tree_pointer n9 = (tree_pointer)malloc(sizeof(tree_node));
	//tree_pointer n16 = (tree_pointer)malloc(sizeof(tree_node));




	n1->left = n2;
	n1->data = 10;
	n1->right = n3;

	n2->left = n4;
	n2->data = 20;
	n2->right = n5;

	n3->left = n6;
	n3->data = 30;
	n3->right = n7;

	n4->left = NULL;
	n4->data = 40;
	n4->right = NULL;

	n5->left = NULL;
	n5->data = 50;
	n5->right = NULL;

	n6->left = NULL;
	n6->data = 60;
	n6->right = NULL;

	n7->left = NULL;
	n7->data = 70;
	n7->right = NULL;


	//왼쪽으로만 연결
	//n1->left = n2;
	//n1->data = 10;
	//n1->right = NULL;
	//
	//n2->left = n4;
	//n2->data = 20;
	//n2->right = NULL;

	//n4->left = n8;
	//n4->data = 40;
	//n4->right = NULL;

	//n8->left = n16;
	//n8->data = 80;
	//n8->right = NULL;

	//n16->left = NULL;
	//n16->data = 160;
	//n16->right = NULL;

	
	return n1;

}

int bt_count(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;

	return (1 + bt_count(ptr->left) + bt_count(ptr->right));
}

int bt_sum(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;

	
	return  bt_sum(ptr->left) + bt_sum(ptr->right);
}

int bt_height(tree_pointer ptr)
{
	int height = 0;
	if (ptr == NULL)
		return 0;

	height = Max(bt_count(ptr->left), bt_count(ptr->right));

	return log(height+1, 2) + 1;


}

void bt_show_preorder(tree_pointer ptr)
{
	if (ptr != NULL)
	{
		printf("%d ", ptr->data);
		bt_show_preorder(ptr->left);
		bt_show_preorder(ptr->right);
	}
}

void bt_free(tree_pointer ptr)
{
	if (ptr == NULL)
		return;
	bt_free(ptr->left);
	bt_free(ptr->right);
	printf("free node with item %d ...\n", ptr->data);

	free(ptr);
	
}

int Max(int i, int j)
{
	if (i >= j)
		return i;
	else
		return j;
}