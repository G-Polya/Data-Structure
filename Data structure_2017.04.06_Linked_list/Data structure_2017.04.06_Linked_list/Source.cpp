#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"
void main()
{
	char c, e;
	list_pointer head, p;
	// dummy head ³ëµå
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;
	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case '+':
			e = _getch();
			_putch(e);
			list_insert(head, e); break;
		case '-':
			e = _getch();
			_putch(e);
			list_delete(head, e); break;
		case '?':
			e = _getch();
			_putch(e);
			p = list_search(head, e);
			if (p) {
				printf("\n %c is in the list. \n", e);
				printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
			}
			else printf("\n %c is not in the list \n", e);
			break;
		case 'S':
			list_show(head); break;
		case 'Q':
			printf(¡°\n¡±);
			exit(1);
		default: break;
		}
	}
}