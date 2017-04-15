#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"


int main()
{

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
