#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"
void main()
{
	char c, e;
	list_pointer head, p;
	// dummy head 노드
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;
	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case '+':
			e = _getch();
			_putch(e);
			list_insert(head, e); break;
		case '-':
			e = _getch();
			_putch(e);
			list_delete(head, e); break;
		case '?':
			e = _getch();
			_putch(e);
			p = list_search(head, e);
			if (p) {
				printf("\n %c is in the list. \n", e);
				printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
			}
			else printf("\n %c is not in the list \n", e);
			break;
		case 'S':
			list_show(head); break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

void list_insert(list_pointer head, Element e)
{
	list_pointer New;
	New = (list_pointer)malloc(sizeof(list_node));		//list_node형 메모리할당

	int temp = head->link;
	head->link = New;
	New->link = temp;
	New->data = e;
	
}

list_pointer list_search(list_pointer head, Element e)
{
	list_pointer p = head;
	while (p)
	{
		if (p->data == e)
			return p;
		p = p->link;		//next node로 이동
	}
	return NULL;
}

void list_delete(list_pointer head, Element e)
{
	list_pointer node = head;
	list_pointer temp = (list_pointer)malloc(sizeof(list_node));
	while (node->link)
	{
		if (node->link->data == e)
		{
			node->link = node;
			free(node);
		}
		node = node->link;
	}
	

	
}

bool list_empty(list_pointer head)
{
	if (head->link == NULL)
	{
		printf("\nList is Empty\n");
		return true;
	}
}

void list_show(list_pointer head)
{
	list_pointer p = head;
	printf("\n");
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->link;
	}
}