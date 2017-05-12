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
		c = _getch();
		_putch(c);
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

//root를 dummyhead로 만들고 초기값으로 초기화
void bst_initialize()
{
	root = (tree_pointer)malloc(sizeof(tree_node));

	root->left = NULL;

	root->right = NULL;

	strcpy(root->w1, "DanceDance");			

	strcpy(root->w2, "락킹개짱");

	return;
}

void bst_insert(char* w1, char* w2)		//입력된 영어문자열과 국어문자열을 가지는 node 삽입
{
	tree_pointer p = root;				//처음시작은 root
	tree_pointer newNode = (tree_pointer)malloc(sizeof(tree_node));	//새로운 node생성

	int compare;		//문자열비교 결과가 저장될 변수

	newNode->left = NULL;
	newNode->right = NULL;

	//newNode에 입력된 문자열 저장
	strcpy(newNode->w1, w1);		
	strcpy(newNode->w2, w2);

	while (1)
	{
		compare = strcmp(p->w1, newNode->w1);		//영어단어가 비교(key값 비교)
		if (compare < 0)							//p의 w1(p의 key값)가 newNode의 w1보다 작다. 오른쪽에서 작업
		{
			if (p->right == NULL)
			{
				p->right = newNode;					//오른쪽이 비었다면 오른쪽에 삽입
				break;

			}
			else
				p = p->right;						//비어있지 않으면 다음으로 넘어감
		}
		else                                        //p의 w1(p의 key값)가 newNode의 w1보다 크다. 왼쪽에서 작업
		{
			if (p->left == NULL)
			{
				p->left = newNode;					//왼쪽이 비어있으면 왼쪽에 삽입
				break;
			}
			else
			{
				p = p->left;						//비어있지 않으면 다음으로 넘어감
			}
			return;
		}
	}
}

//입력을 txt파일로 저장(사전만들기)
int build_dictionary(char *fname)
{
	char w1[100], w2[100];

	FILE *fp = fopen(fname, "r");
	int count = 0;

	while (!feof(fp))	//파일의 끝에 다다를때까지 반복
	{
		fscanf(fp, "%s %s", w1, w2);		//txt파일에 입력
		bst_insert(w1, w2);					//w1,w2를 멤버로 가지는 node삽입
		count++;
	}
	fclose(fname);

	return count;
}

char* bst_search(char* w1)
{
	tree_pointer p = root;		//처음시작은 root
	int compare;				//문자열비교 결과가 저장될 변수

	char* result = NULL;

	while (1)							//다음으로 넘어가는 과정을 통해서 원하던걸 찾을때까지 반복
	{
		compare = strcmp(p->w1, w1);	//parameter로 주어진 문자열(key)과 p의 w1(key)비교값저장
		if (compare < 0)				//parameter가 더 크다면, 즉 입력된 key가 더 크다면
		{
			if (p->right == NULL)
				break;
			else
				p = p->left;			//다음오른쪽으로 넘어감
		}
		else if (compare > 0)			//parameter가 더 작다면
		{
			if (p->left == NULL)
				break;
			else
				p = p->left;			//다음 왼쪽으로 넘어감
		}
		else                            //내가 찾던 문자열 w1
		{
			result = p->w2;
			break;
		}
	}
	return result;						//내가 찾던 문자열 w1을 가지는 node의 멤버 w2(data) 반환
}
//여기서 p는 서브트리의 처음 node
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