#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

int main()
{
	char c, e;
	printf("********* Command *********\n");
	printf("+<c>: Push c, -: Pop,\n");
	printf("S: Show, Q: quit\n");
	printf("***************************\n\n");


		while (1) {
			printf("\nCommand> ");
			c = _getch();									//�����Է�
			_putch(c);										//�Է¹��ڸ��� ���
			c = toupper(c);
			switch (c) 
			{
			case '+':										//'+'�˶� �����Է��� �ѹ��� �ް�, �� ���ڸ� stack�� push
				e = _getch();									
				_putch(e);
				push(e);
				break;
			case '-':										//'-'�϶� pop
				e = pop();
				printf("\n %c \n", e);
				break;
			case 'S':										//���� stack���¸� ������
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

void stack_full()											//stack�� ����������		
{
	printf("Stack is full!!!\n");
}

void stack_empty()											//stack�� �������			
{
	printf("\nStack is empty!!!\n");
}

void push(Element e)
{
	if (top >= MAX_SIZE - 1)								//stack�� ����������
	{
		stack_full();
		return;
	}
	else
		stack[++top] = e;									//�������� ������ top�� ��ĭ �ø��� �װ��� �Է��� �Ҵ�
}

Element pop()
{
	if (top == -1)											//stack�� �� �������
	{
		stack_empty();
		return;
	}
	else
		return stack[top--];								//�� ������� ������ ���� ������ ���Ҹ� ��ȯ�ϰ� �� ĭ ������
}

void stack_show()											//stack�� ���� ���¸� �����ִ� �Լ�
{
	printf("\n");
	for (int i = 0; i <= top; i++)
	{
		printf(" %c ", stack[i]);
	}
}