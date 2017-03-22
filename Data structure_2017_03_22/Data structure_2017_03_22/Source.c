#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main()
{
	char c;
	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c)
		{
		case '+':
			c = _getch();
			_putch(c);
			list_insert(c);
			break;
		case '-':
			c = _getch();
			_putch(c);
			list_delete(c);
			break;

		case 'E':
			if (list_empty()) printf("\nTRUE \n");
			else printf("\nFALSE \n");
			break;
		case 'F':
			if (list_full()) printf("\nTRUE \n");
			else printf("\nFALSE \n");
			break;
		case 'S':
			list_show(List);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}

	}

	return 0;
	
}

boolean list_full()
{
	if (size == MaxSize)
		return true;
	else
		return false;
}

boolean list_empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

void list_insert(Element e)
{
	if (size < MaxSize)
	{
		List[size] = e;
		size++;
	}
	else
	{
		printf("\nList is Full!!\n");
	}
}

void list_delete(Element e)
{
	if (size > 0)
	{
		if (List[0] == e)
		{
			List[0] = List[1];
			List[1] = List[2];
			List[2] = NULL;
			size--;
		}
		else if (List[1] == e)
		{
			List[1] = List[2];
			List[2] = NULL;
			size--;
		}
		else if (List[2] == e)
		{
			List[2] = NULL;
			size--;
		}

		else if (List[0] != e && List[1] != e &&List[2] != e)
			printf("\nData does not exist!!!\n");
	}
}

void list_show(Element *L)
{
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%c   ", L[i]);

	if (size == 0)
		printf("\nList is Empty!!\n");
}