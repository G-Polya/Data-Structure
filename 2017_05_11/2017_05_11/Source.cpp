#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"

int main() 
{
	char c, grade;
	int id;

	bst_initalize();

	printf("*************COMMAND*************\n");
	printf("I : INSERT DATA,  S : SEARCH DATA\n");
	printf("P : PRINT INORDER,  Q : QUIT\n");
	printf("*********************************\n");

	while (1) {
		printf("\nCOMMAND >>");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
		case 'I':
			printf("\n ID AND GRADE : ");
			scanf(" %d %c", &id, &grade);
			bst_insert(id, grade);
			break;
		case 'S':
			printf("\n ID : ");
			scanf(" %d", &id);
			grade = bst_search(id);
			if (grade) {
				printf(" GRADE OF %d : %c", id, grade);
			}
			else {
				printf(" CANNOT FIND %d !!!", id);
			}
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		default:
			printf("\nWRONG COMMAND !!!\n");
			break;
		}
	}

	return 0;


}

void bst_initalize()		//root를 더미헤드로 만들고 초기값으로 초기화
{
	root = (tree_pointer)malloc(sizeof(tree_node));

	root->key = INT_MAX;	//추가되는 노드의 key와 root의 key를 비교할때 새로운 노드가 root의 왼쪽 자식으로 가게함

	root->data = NULL;

	root->left = NULL;

	root->right = NULL;

	return;
}

void bst_insert(int key, char data)
{
	tree_pointer p = root; //처음은 root

	//새로운 노드 생성
	tree_pointer newNode = (tree_pointer)malloc(sizeof(tree_node));
	newNode->key = key;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	//newNode의 key값과 p의 그것을 비교해서 newNode를 알맞은 위치에 삽입.알맞은 위치에 삽입될 때까지 반복
	while (1)
	{
		if (p->key < key)			//p의 key가 삽입대상의 key보다 작다면 
		{
			if (p->right == NULL)	//p의 오른쪽이 비었다면
			{
				p->right = newNode; //오른쪽에 삽입
				break;
			}
			else                    //비어있지 않다면
			{
				p = p->right;		//기존의 p의 오른쪽자식이 새로운 p가 된다. 다음으로 넘어가는 과정
			}
		}
		else                        //p의 key가 삽입대상의 key보다 크다면
		{
			if (p->left == NULL)	//p의 왼쪽이 비었다면
			{
				p->left = newNode;	//왼쪽에 삽입
				break;
			}
			else
			{
				p = p->left;		//기존 p의 왼쪽자식이 새로운 p가 된다. 다음으로 넘어가는 과정
			}
		}
	}
	return;

}

char bst_search(int key)
{
	tree_pointer p = root;			//처음시작은 root
	char result = NULL;
	while (1)						//입력된 key에 알맞은 tree의 key를 찾을때까지 반복
	{
		if (p->key < key)			//오른쪽
		{
			if (p->right == NULL)
				break;
			else
				p = p->right;		//다음으로 넘어감
		}
		else if (p->key > key)		//왼쪽
		{
			if (p->left == NULL)
				break;
			else
				p = p->left;		//다음으로 넘어감
		}
		else                        //내가 찾던 key
		{
			result = p->data;		
			break;
		}
	}

	return result;				   //내가 찾던 key를 가지는 node의 데이터 반환
}

//여기서 p는 서브트리의 처음 node
void bst_show_inorder(tree_pointer p)	
{
	if (p != NULL)
	{
		bst_show_inorder(p->left);
		if (p != root)
		{
			printf("%d %c\n", p->key, p->data);
		}
		bst_show_inorder(p->right);
	}
	return;
}

