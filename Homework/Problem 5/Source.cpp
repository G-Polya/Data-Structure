#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"


int main()
{
	head = (stack_pointer)malloc(sizeof(stack));
	head->item = NULL;
	head->link = NULL;

	char c, e;

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
			push(e);
			break;
		case '-':
			if (is_stack_empty())
			{
				printf("\n Queue is empty !!! \n");
			}
			else
			{
				e = pop();
				printf("\n %c ", e);
			}
			break;
		case 'S': stack_show(); break;
		case 'Q': printf("\n"); exit(1);
		default: break;
		}
	}
}

boolean is_stack_empty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

void push(Element e)
{
	stack_pointer temp = (stack_pointer)malloc(sizeof(stack));
	temp->item = e;
	temp->link = NULL;

	if (is_stack_empty())
	{
		top = temp;
	}
	else
	{
		top->link = temp;
		top = temp;
	}

}

Element pop()
{
	stack_pointer temp;
	Element item;

	temp = top;
	item = top->item;
	top = NULL;
	free(temp);

	return item;
}

void stack_show()
{
	printf("\n");
	for (stack_pointer i = head; i != NULL; i = i->link)
	{
		printf(" %c ", i->item);
	}
}