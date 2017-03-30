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

void stack_full()											//stack이 꽉차있을떄		
{
	printf("Stack is full!!!\n");
}

void stack_empty()											//stack이 비었을때			
{
	printf("\nStack is empty!!!\n");
}

void push(Element e)
{
	if (top >= MAX_SIZE - 1)								//stack이 꽉차있을때
	{
		stack_full();
		return;
	}
	else
		stack[++top] = e;									//꽉차있지 않으면 top을 한칸 올리고 그곳에 입력을 할당
}

Element pop()
{
	if (top == -1)											//stack이 텅 비었을때
	{
		stack_empty();
		return;
	}
	else
		return stack[top--];								//텅 비어있지 않으면 가장 나중의 원소를 반환하고 한 칸 내린다
}

void stack_show()											//stack의 현재 상태를 보여주는 함수
{
	printf("\n");
	for (int i = 0; i <= top; i++)
	{
		printf(" %c ", stack[i]);
	}
}