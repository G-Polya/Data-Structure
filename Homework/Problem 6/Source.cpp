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
	
	
	//원소삽입
	list_insert(head1, 2);
	list_insert(head1, 3);
	list_insert(head1, 6);
	list_insert(head1, 7);

	list_insert(head2, 1);
	list_insert(head2, 4);
	list_insert(head2, 5);


	list_show(head1);
	list_show(head2);

	//새로운 head
	list_pointer new_head = (list_pointer)malloc(sizeof(list_node));
	new_head->data = NULL;
	new_head->link = NULL;

	list_pointer temp;

	temp = merge(head1, head2);			//linked_list 두개 합병
	new_head = merge_sort(temp);		//정렬

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
		if (p->data > 1000)
			break;
		printf("%d ", p->data);
		p = p->link;
		
	}
}

//합병 정렬(list를 합병한 후 정렬한게 아니라, "합병 정렬"이다. 
//list를 merge한 다음, 정렬의 수단으로써 merge_sort를 사용한것뿐이지. 정렬수단으로 bubble_sort를 사용해도 무방하다 
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

//list합병
list_pointer merge(list_pointer a, list_pointer b)
{
	list_pointer dummyhead, curr;
	dummyhead = (list_pointer)malloc(sizeof(list_node));//dummyhead

	curr = dummyhead;//현재상태 == dummy

	while (a != NULL && b != NULL)		//입력받은 parameter인 linked_list가 비어있지 않다
	{
		if (a->data <= b->data)			
		{
			curr->link = a;				//작은놈 연결
			a = a->link;				//다음것으로 넘어감
		}
		else
		{
			curr->link = b;				//작은놈 연결
			b = b->link;				//다음것으로 넘어감
		}
		curr = curr->link;				//현재상태 넘어감
	}
	curr->link = (a == NULL) ? b : a;	//넘어가진 현재상태는 a가 비어있으면 b이고 비어있지 않으면 a이다.
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

