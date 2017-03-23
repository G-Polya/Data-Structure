#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main()
{
	//처음 시작화면, 수행하고자 하는 작업을 선택
	char c;
	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1)
	{
		printf("\nCommand> ");						//입력화면
		c = _getch();								//문자입력
		_putch(c);									//문자출력
		c = toupper(c);								
		switch (c)									//입력받은 문자가 무엇이냐에 따라 수행하는 작업이 달라짐
		{
		case '+':									//입력받은 문자가 '+'일때, 문자를 다시한번 입력받아 list에 삽입
			c = _getch();
			_putch(c);
			list_insert(c);				
			break; 
		case '-':									//입력받은 문자가 '-'일때, 문자를 다시한번 입력받아 그 문자를 list에서 삭제 
			c = _getch();
			_putch(c);
			list_delete(c);
			break;

		case 'E':
			if (list_empty()) printf("\nTRUE \n");	//list가 비엇을 경우 true, 그렇지 않을 경우 false
			else printf("\nFALSE \n");
			break;
		case 'F':
			if (list_full()) printf("\nTRUE \n");	//list가 가득차있을 경우 true, 그렇지 않읋경우 false
			else printf("\nFALSE \n");
			break;
		case 'S':
			list_show(List);						//현재상태의 list출력
			break;
		case 'Q':
			printf("\n");							//작업 끝
			exit(1);
		default:
			break;
		}

	}

	return 0;
	
}

boolean list_full()									//list가 가득차있는지를 확인하는 함수
{
	if (size == MaxSize)
		return true;								
	else
		return false;								//list가 가득차있을 경우 true, 아닐 경우 false
}

boolean list_empty()								//list가 비어있는지 확인하는 함수
{
	if (size == 0)
		return true;
	else
		return false;								//list가 비어있으면 true, 아니면 true
}

void list_insert(Element e)							//list에 문자를 삽입하는 함수
{
	if (size < MaxSize)								//list의 크기가 최대크기보다 작으면
	{
		List[size] = e;								//전달인자를 리스트의 마지막에 삽입하고 size증가
		size++;
	}
	else
	{
		printf("\nList is Full!!\n");				//list가 가득차있을경우
	}
}

void list_delete(Element e)							//list에서 문자를 삭제하는 함수, 삭제하고 한칸 씩 당겨야한다
{
	if (size > 0)									//list가 비어있지 않음을 가정
	{	
		if (List[0] == e)							//만약 list의 원소를 삭제하고자 한다면			
		{
			List[0] = List[1];
			List[1] = List[2];
			List[2] = NULL;			
			size--;									//한칸 씩 당기고 마지막엔 NULL, 그리고 list의 크기를 줄인다.				
		}
		else if (List[1] == e)
		{
			List[1] = List[2];
			List[2] = NULL;
			size--;
		}
		else if (List[2] == e)
		{
			List[2] = NULL;
			size--;
		}

		else if (List[0] != e && List[1] != e &&List[2] != e) //전달인자가 list의 원소가 아니라면 다음을 출력
			printf("\nData does not exist!!!\n");			
	}
}

void list_show(Element *L)							//list의 현재상태를 보여주는 함수
{
	printf("\n");
	for (int i = 0; i < size; i++)					//list의 size만큼 출력한다
		printf("%c   ", L[i]);

	if (size == 0)									//list가 비어있다면 다음을 출력
		printf("\nList is Empty!!\n");				
}