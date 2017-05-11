/*
1. stack 만들기
2. 피연산자인지 연산자인지 판단
3. 연산과정
 1) token(초기입력값)이 피연산자인지 연산자인지 판단
 2) 피연산자라면 피연산자 push
 3) 연산자라면 피연산자 두개 pop
 4) token이 무슨 연산자 인지에 따라서 다르게 연산
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Header.h"

int main()
{
	printf("Enter virtual machine commands:\n");

	char c, e, e2, e1;
	while(1)
	{
		printf("\n");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c)
		{
		case 'P':
			printf(" ");
			e = _getch() -'0';
			_putch(e + '0');
			push(e);
			break;

		case 'R':
			e = result();
			printf(" %d", e);
			break;

		case 'A':
			e2 = result(); e1 = result();
			push(e2 + e1); 
			break;

		case 'S':
			e2 = result(); e1 = result();
			push(e2 - e1);
			break;

		case 'M':
			e2 = result(); e1 = result();
			push(e2 * e1);
			break;

		case 'D':
			e2 = result(); e1 = result();
			push(e2 / e1);
			break;

		default:
			break;
		}
	}
	return 0;
}

boolean stack_full()
{
	if (top >= MAX_SIZE - 1)
		return true;
	else
		return false;
}

boolean stack_empty()
{
	if (top < 0)
		return true;
	else
		return false;
}

void push(Element e)
{
	if (stack_full())
		printf("Stack is Full!!\n");
	else
	{
		Stack[++top] = e;
	}
}

Element result()
{
	if (stack_empty())
		printf("Stack is Empty!!\n");
	else
		return Stack[top--];
}

//boolean is_operand(char c)
//{
//	if (('0' <= c) && (c <= '9'))
//		return true;
//	else
//		return false;
//}
//
//boolean is_operator(char c)
//{
//	if (c == '+')
//		return true;
//	if (c == '-')
//		return true;
//	if (c == '*')
//		return true;
//	if (c == '/')
//		return true;
//	else
//		return false;
//}
