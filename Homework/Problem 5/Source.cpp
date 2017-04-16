#include <stdio.h>
#include "linked_stack.h"
#include <stdlib.h>

int main()
{
	char c, e;
	printf("********* Command *********\n");
	printf("+<c>: Push c, -: Pop,\n");
	printf("S: Show, Q: quit\n");
	printf("***************************\n\n");


	while (1) {
		printf("\nCommand> ");
		c = _getch();									//문자입력
		_putch(c);										//입력받자마자 출력
		c = toupper(c);
		switch (c)
		{
		case '+':										//'+'알때 문자입력을 한번더 받고, 그 문자를 stack에 push
			e = _getch();
			_putch(e);
			push(e);
			break;
		case '-':										//'-'일때 pop
			e = pop();
			printf("\n %c \n", e);
			break;
		case 'S':										//현재 stack상태를 보여줌
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

void stack_show()
{
	printf("\n");

	for (stack_pointer p = top; p != NULL; p = p->link)
	{
		printf("%c ", p->item);
	}

	

	/*stack_pointer p = top;
	
	while (p)
	{
		printf("%c ", p->item);
		p = p->link;
	}
	*/
}

void push(Element e)
{
	stack_pointer temp = (stack_pointer)malloc(sizeof(stack));
	temp->item = e;
	temp->link = top;
	top = temp;
}

Element pop()
{
	Element item;
	stack_pointer temp = top;
	if (top == NULL)
	{
		printf("\n\n Stack is empty! \n");
		return 0;
	}
	else
	{
		item = temp->item;
		top = temp->link;
		free(temp);
		return item;
	}
}
