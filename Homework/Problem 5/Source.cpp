#include <stdio.h>
#include "linked_stack.h"

int main()
{
	char *express = "a*[b-{c+(d-e]/(f-g)}-h]+(i-j)";
	printf("%s", express);
	if (check(express) == 1)
		printf("\n ������ ��ȣ�� �°� ���Ǿ����ϴ�!\n");
	else
		printf("\n ������ ��ȣ�� Ʋ�Ƚ��ϴ� ��!!");
	getchar();
}

//a*[b-{c+(d-e)/(f-g)}-h]+(i-j)
//��ȣ �˻�
int check(char *exp)
{
	char symbol, open_pair;					//symbol:���ڿ� ����, open_pair: ¦���߱� ����
	int length = strlen(exp);
	top = NULL;
	for (int i = 0; i < length; i++)		//���ڿ����̸�ŭ, �� ���ڿ� ������. for(int i = 0; exp[i] != NULL; i++)�� ��ü����
	{
		symbol = exp[i];					//symbol�� parameter�� �Էµ� ���ڿ��� ����; �ݺ������� ���� ���ڿ��� �����Ұ� �����ݺ��� �Ǳ������� symbol�� ���Եȴ�
											//�ᱹ ���ڿ��� ��� ���ҿ� ���� �˻�(�۾�)�� �̷������.
		switch (symbol)
		{
		case'(':
		case'{':
		case'[':
			push(symbol);
			break;							//���ڿ��� ���Ұ� '(', '{' '['�̸� �� ���Ҹ� push
		case')':
		case'}':
		case']':
			if (is_stack_empty())				//���ڿ��� ���Ұ� ')', '}', ']'�̰� stack�� �������
				return 0;
			else
			{
				open_pair = pop();				//���ڿ��� ���Ұ� ')', '}', ']'������ stack�� ������� �ʾ�����, stack�� ������ ���Ҹ� pop�ؼ� open_pair�� ����
				if ((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}')
					|| (open_pair == '[' && symbol != ']'))						//open_pair�� symbol�� ¦�� ������. ��, ���� ������ ��ȣ���� ����, 
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
