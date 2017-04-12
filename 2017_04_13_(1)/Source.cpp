#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"
void main()
{
	char c, e;
	front = rear = NULL;


	while (1)
	{
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c)
		{
		case '+':
			e = _getch();
			_putch(e);
			addq(e);
			break;
		case '-':
			if (is_queue_empty())
			{
				printf("\n Queue is empty !!! \n");
			}
			else
			{
				e = deleteq();
				printf("\n %c ", e);
			}
			break;
		case 'S': queue_show(); break;
		case 'Q': printf("\n"); exit(1);
		default: break;
		}
	}
}


boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}


void addq(Element e)
{
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;


	if (is_queue_empty())					//queue가 비어있으면
	{
		front = rear = temp;					//queue의 처음 원소로 삽입
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}


Element deleteq()
{
	queue_pointer temp;
	Element item;


	temp = front;
	item = front->item;


	front = front->link;


	free(temp);


	return item;
}


void queue_show()
{
	printf("\n");
	for (queue_pointer i = front; i != NULL; i = i->link)		//i가 NULL이 되면 반복중지
	{
		printf("%c ", i->item);
	}
}
