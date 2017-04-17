#include <stdio.h>
#include "linked_stack.h"

int main()
{
	char *express = "a*[b-{c+(d-e]/(f-g)}-h]+(i-j)";
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
	for (int i = 0; i < length; i++)		//문자열길이만큼, 즉 문자열 끝까지. for(int i = 0; exp[i] != NULL; i++)로 대체가능
	{
		symbol = exp[i];					//symbol은 parameter로 입력된 문자열의 원소; 반복문으로 인해 문자열의 모든원소가 다음반복이 되기전까지 symbol에 대입된다
											//결국 문자열의 모든 원소에 대해 검사(작업)이 이루어진다.
		switch (symbol)
		{
		case'(':
		case'{':
		case'[':
			push(symbol);
			break;							//문자열의 원소가 '(', '{' '['이면 그 원소를 push
		case')':
		case'}':
		case']':
			if (is_stack_empty())				//문자열의 원소가 ')', '}', ']'이고 stack이 비었으면
				return 0;
			else
			{
				open_pair = pop();				//문자열의 원소가 ')', '}', ']'이지만 stack이 비어있지 않았으면, stack의 마지막 원소를 pop해서 open_pair에 저장
				if ((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}')
					|| (open_pair == '[' && symbol != ']'))						//open_pair와 symbol이 짝이 맞으면. 즉, 왼쪽 오른쪽 괄호수가 같고, 
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

boolean is_stack_empty()
{
	if (top == NULL)
		return true;
	else
		return false;
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
	if (is_stack_empty())
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
