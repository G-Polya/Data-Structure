#include <stdio.h>
#include "linked_stack.h"

int main()
{
	char *express = "a*[b-{c+(d-e)/(f-g)}-h]+(i-j)";
	printf("%s", express);
	if (check(express) == 1)
		printf("\n 수식의 괄호가 맞게 사용되었습니다!\n");
	else
		printf("\n 수식의 괄호가 틀렸습니다 떙!!");
	getchar();
}

//a*[b-{c+(d-e)/(f-g)}-h]+(i-j)
//괄호 검사
int check(char *exp)
{
	char symbol, open_pair;					//symbol:문자열 원소, open_pair: 짝맞추기 위해
	int length = strlen(exp);
	top = NULL;
	for (int i = 0; exp[i] != NULL;i++)		//문자열길이만큼, 즉 문자열 끝까지. for(int i = 0; exp[i] != NULL; i++)로 대체가능
	{
		symbol = exp[i];
		switch (symbol)
		{
		case'(':
		case'{':
		case'[':
			push(symbol);
			break;
		case')':
		case'}':
		case']':
			if (top == NULL)
				return 0;
			else
			{
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}')
					|| (open_pair == '[' && symbol != ']'))
					return 0;
				else
					break;
			}	
		}
	}
	if (top == NULL)
		return 1;
	else
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

Element peek()
{
	Element item;
	if (top == NULL)
	{
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else
	{
		item = top->item;
		return item;
	}
}

void del()
{
	stack_pointer temp;
	if (top == NULL)
	{
		printf("\n\n Stack is empty!\n");
	}
	else
	{
		temp = top;
		top = top->link;
		free(temp);
	}
}
