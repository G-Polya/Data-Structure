#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

int main()
{
	char c, e;
	
		while (1) {
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
				e = pop();
				printf("\n %c \n", e);
				break;
			case 'S':
				stack_show();
				break;
			case 'Q':
				printf("\n");
				exit(1);
			default: break;
			}
		}

		return 0;
}

void stack_full()
{
	printf("Stack is full!!!\n");
}

void stack_empty()
{
	printf("\nStack is empty!!!\n");
}

void push(Element e)
{
	if (top >= MAX_SIZE - 1)
	{
		stack_full();
		return;
	}
	else
		stack[++top] = e;
}

Element pop()
{
	if (top == -1)
	{
		stack_empty();
		return;
	}
	else
		return stack[top--];
}

void stack_show()
{
	printf("\n");
	for (int i = 0; i <= top; i++)
	{
		printf(" %c ", stack[i]);
	}
}