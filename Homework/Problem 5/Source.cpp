#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linked_stack.h"
#include <stdlib.h>

int main()
{
	char exp[100]; // postfix expression
	int result;
	while (1) {
		printf("\n Input postfix expression: ");
		scanf("%s", exp);
		result = eval_postfix(exp);
		printf(" Result = %d \n\n", result);
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

boolean is_number(char c)				//입력이 숫자인지 아닌지 확인
{
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}

boolean is_op(char c)					//입력이 연산자인지 확인
{
	if (c == '+')
		return true;
	else if (c == '-')
		return true;
	else if (c == '*')
		return true;
	else if (c == '/')
		return true;
	else
		return false;
}

int eval_postfix(char *exp)				//후위표기연산
{


	int i = 0;
	char op, op2, op1;
	char token = exp[0];				//초기입력값
	while (token != NULL)
	{
		if (is_number(token))
		{
			op = token - '0';			//문자(char)를 아스키코드가 아닌 정수형숫자로 바꿈
			push(op);					//입력이 숫자면 psuh 
		}
		else if (is_op(token))
		{
			op2 = pop(); op1 = pop();	//입력이 연산자면 마지막 두개가지고 다음의 작업
			switch (token)
			{
			case '+': push(op1 + op2); break;
			case '-': push(op1 - op2); break;
			case '*': push(op1 * op2); break;
			case '/':push(op1 / op2); break;
			}
		}
		token = exp[++i];				//토큰에 다음 입력값 대입
	}
	return pop();						//연산결과 반환
}