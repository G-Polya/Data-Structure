#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "QueueArray.h"

int main()
{
	char c, e;

	while (1)
	{
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case '+':
			e = _getch();
			_putch(e);
			AddQ(e);
			break;
		case '-':
			e = DeleteQ();
			printf("\n %c \n", e);
			break;
		case 'S':
			Queue_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;

		}
		
	}
	return 0;
}


void Q_isFull()
{
	printf("\nQueue is Full!!!\n");
}



void Q_isEmpty()
{
	printf("\nQueue is Empty!!!\n");
}

void AddQ(char item)
{
	if (rear == Q_size - 1)
	{
		Q_isFull();
		return;
	}
	else
		QueueArray[++rear] = item;
}

char DeleteQ()
{
	if (front == rear)
	{
		Q_isEmpty();
		return;
	}
	else
		return QueueArray[++front];
}

void Queue_show()
{
	printf("\n");
	for (int i = front + 1; i <= rear; i++)
	{
		printf(" %c ", QueueArray[i]);
	}
}