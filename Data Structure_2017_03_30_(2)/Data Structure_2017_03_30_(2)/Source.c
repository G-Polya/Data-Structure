#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
void main()
{
	char exp[100]; // postfix expression
	int result;
	while (1) {
		printf("\n Input postfix expression: ");
		scanf("%s", exp);
		result = eval_postfix(exp);
		printf(" Result = %d \n\n", result);
	}
}

void stack_full()
{
	printf("Stack is full!!!\n");
}

void stack_empty()
{
	printf("\nStack is empty!!!\n");
}

void push(int e)
{
	if (top >= MAX_SIZE - 1)
	{
		stack_full();
		return;
	}
	else
		stack[++top] = e;
}

int pop()
{
	if (top == -1)
	{
		stack_empty();
		return;
	}
	else
		return stack[top--];
}

boolean is_number(char c)
{
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}

boolean is_op(char c)
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

int eval_postfix(char *exp)
{
	int i = 0;
	char op, op2, op1;
	char token = exp[0];
	while (token != NULL)
	{
		if (is_number(token))
		{
			op = token - '0';
			push(op);
		}
		else if(is_op(token))
		{
			op2 = pop(); op1 = pop();
			switch (token)
			{
			case '+': push(op1 + op2); break;
			case '-': push(op1 - op2); break;
			case '*': push(op1 * op2); break;
			case '/':push(op1 / op2); break;
			}
		}
		token = exp[++i];
	}
	return pop();
}