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

void bst_initalize()		//root�� �������� ����� �ʱⰪ���� �ʱ�ȭ
{
	root = (tree_pointer)malloc(sizeof(tree_node));

	root->key = INT_MAX;	//�߰��Ǵ� ����� key�� root�� key�� ���Ҷ� ���ο� ��尡 root�� ���� �ڽ����� ������

	root->data = NULL;

	root->left = NULL;

	root->right = NULL;

	return;
}

void bst_insert(int key, char data)
{
	tree_pointer p = root; //ó���� root

	//���ο� ��� ����
	tree_pointer newNode = (tree_pointer)malloc(sizeof(tree_node));
	newNode->key = key;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	//newNode�� key���� p�� �װ��� ���ؼ� newNode�� �˸��� ��ġ�� ����.�˸��� ��ġ�� ���Ե� ������ �ݺ�
	while (1)
	{
		if (p->key < key)			//p�� key�� ���Դ���� key���� �۴ٸ� 
		{
			if (p->right == NULL)	//p�� �������� ����ٸ�
			{
				p->right = newNode; //�����ʿ� ����
				break;
			}
			else                    //������� �ʴٸ�
			{
				p = p->right;		//������ p�� �������ڽ��� ���ο� p�� �ȴ�. �������� �Ѿ�� ����
			}
		}
		else                        //p�� key�� ���Դ���� key���� ũ�ٸ�
		{
			if (p->left == NULL)	//p�� ������ ����ٸ�
			{
				p->left = newNode;	//���ʿ� ����
				break;
			}
			else
			{
				p = p->left;		//���� p�� �����ڽ��� ���ο� p�� �ȴ�. �������� �Ѿ�� ����
			}
		}
	}
	return;

}

char bst_search(int key)
{
	tree_pointer p = root;			//ó�������� root
	char result = NULL;
	while (1)						//�Էµ� key�� �˸��� tree�� key�� ã�������� �ݺ�
	{
		if (p->key < key)			//������
		{
			if (p->right == NULL)
				break;
			else
				p = p->right;		//�������� �Ѿ
		}
		else if (p->key > key)		//����
		{
			if (p->left == NULL)
				break;
			else
				p = p->left;		//�������� �Ѿ
		}
		else                        //���� ã�� key
		{
			result = p->data;		
			break;
		}
	}

	return result;				   //���� ã�� key�� ������ node�� ������ ��ȯ
}

//���⼭ p�� ����Ʈ���� ó�� node
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

