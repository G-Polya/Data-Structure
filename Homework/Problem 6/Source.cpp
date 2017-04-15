//참고코드 http://stackoverflow.com/questions/7685/merge-sort-a-linked-list

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"
#include <assert.h>
void main()
{

	list_pointer head1, head2;
	// dummy head 노드
	head1 = (list_pointer)malloc(sizeof(list_node));
	head1->data = NULL;
	head1->link = NULL;

	head2 = (list_pointer)malloc(sizeof(list_node));
	head2->data = NULL;
	head2->link = NULL;

	for (int i = 1; i <= 9; i++)
	{
		if (i % 3 == 0)
			list_insert(head1, i);

		if (i % 4 == 0)
			list_insert(head2, i);
	}
	list_show(head1);
	list_show(head2);

	list_pointer new_head = (list_pointer)malloc(sizeof(list_node));
	new_head->data = NULL;
	new_head->link = NULL;

	list_pointer temp;

	temp = merge(head1, head2);
	new_head = merge_sort(temp);

	list_show(new_head);

	
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
		printf("%d ", p->data);
		p = p->link;
	}
}

list_pointer merge_sort(list_pointer head)
{
	if (head == NULL || head->link == NULL)
	{
		return head;
	}

	list_pointer middle = getMiddle(head);
	list_pointer sHalf = middle->link;
	middle->link = NULL;

	return merge(merge_sort(head), merge_sort(sHalf));
}

list_pointer merge(list_pointer a, list_pointer b)
{
	list_pointer dummyhead, curr;
	dummyhead = (list_pointer)malloc(sizeof(list_node));
	curr = dummyhead;

	while (a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			curr->link = a;
			a = a->link;
		}
		else
		{
			curr->link = b;
			b = b->link;
		}
		curr = curr->link;
	}
	curr->link = (a == NULL) ? b : a;
	return dummyhead->link;
}

list_pointer getMiddle(list_pointer head)
{
	if (head == NULL)
		return head;

	list_pointer slow, fast;
	slow = fast = head;
	while (fast->link != NULL && fast->link->link != NULL)
	{
		slow = slow->link;
		fast = fast->link->link;
	}
	return slow;
}

