#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_dictionary.h"
void main()
{
	char c, fname[20];
	char key[100], *data;
	int wcount;
	//	・・・・・・・・・.
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", key);
			num_comparison = 0;
			data = hash_search(key);
			if (data) printf(" Meaning: %s \n", data);
			else printf(" No such word ! \n");
			printf(" Tatal number of comparison = %d \n", num_comparison);
			break;
		case 'P':
			printf("\n");
			hash_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}