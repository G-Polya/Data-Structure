#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main()
{
	//ó�� ����ȭ��, �����ϰ��� �ϴ� �۾��� ����
	char c;
	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1)
	{
		printf("\nCommand> ");						//�Է�ȭ��
		c = _getch();								//�����Է�
		_putch(c);									//�������
		c = toupper(c);								
		switch (c)									//�Է¹��� ���ڰ� �����̳Ŀ� ���� �����ϴ� �۾��� �޶���
		{
		case '+':									//�Է¹��� ���ڰ� '+'�϶�, ���ڸ� �ٽ��ѹ� �Է¹޾� list�� ����
			c = _getch();
			_putch(c);
			list_insert(c);				
			break; 
		case '-':									//�Է¹��� ���ڰ� '-'�϶�, ���ڸ� �ٽ��ѹ� �Է¹޾� �� ���ڸ� list���� ���� 
			c = _getch();
			_putch(c);
			list_delete(c);
			break;

		case 'E':
			if (list_empty()) printf("\nTRUE \n");	//list�� ����� ��� true, �׷��� ���� ��� false
			else printf("\nFALSE \n");
			break;
		case 'F':
			if (list_full()) printf("\nTRUE \n");	//list�� ���������� ��� true, �׷��� �ʟ���� false
			else printf("\nFALSE \n");
			break;
		case 'S':
			list_show(List);						//��������� list���
			break;
		case 'Q':
			printf("\n");							//�۾� ��
			exit(1);
		default:
			break;
		}

	}

	return 0;
	
}

boolean list_full()									//list�� �������ִ����� Ȯ���ϴ� �Լ�
{
	if (size == MaxSize)
		return true;								
	else
		return false;								//list�� ���������� ��� true, �ƴ� ��� false
}

boolean list_empty()								//list�� ����ִ��� Ȯ���ϴ� �Լ�
{
	if (size == 0)
		return true;
	else
		return false;								//list�� ��������� true, �ƴϸ� true
}

void list_insert(Element e)							//list�� ���ڸ� �����ϴ� �Լ�
{
	if (size < MaxSize)								//list�� ũ�Ⱑ �ִ�ũ�⺸�� ������
	{
		List[size] = e;								//�������ڸ� ����Ʈ�� �������� �����ϰ� size����
		size++;
	}
	else
	{
		printf("\nList is Full!!\n");				//list�� �������������
	}
}

void list_delete(Element e)							//list���� ���ڸ� �����ϴ� �Լ�, �����ϰ� ��ĭ �� ��ܾ��Ѵ�
{
	if (size > 0)									//list�� ������� ������ ����
	{	
		if (List[0] == e)							//���� list�� ���Ҹ� �����ϰ��� �Ѵٸ�			
		{
			List[0] = List[1];
			List[1] = List[2];
			List[2] = NULL;			
			size--;									//��ĭ �� ���� �������� NULL, �׸��� list�� ũ�⸦ ���δ�.				
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

		else if (List[0] != e && List[1] != e &&List[2] != e) //�������ڰ� list�� ���Ұ� �ƴ϶�� ������ ���
			printf("\nData does not exist!!!\n");			
	}
}

void list_show(Element *L)							//list�� ������¸� �����ִ� �Լ�
{
	printf("\n");
	for (int i = 0; i < size; i++)					//list�� size��ŭ ����Ѵ�
		printf("%c   ", L[i]);

	if (size == 0)									//list�� ����ִٸ� ������ ���
		printf("\nList is Empty!!\n");				
}