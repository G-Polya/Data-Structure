#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Header.h"

int main()
{
	char c;


	read_record("grade.txt");
	printf("********** 명령어 ********** \n");
	printf("P: Print all records \n");
	printf("S: Search record\n");
	printf("C: Change record\n");
	printf("W: Wrtie record\n");
	printf("Q: Save and quit\n");
	printf("****************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c)
		{
		case 'P':
			print_record();
			break;
		case 'S':
			search_record();
			break;
		case 'C':
			change_record();
			break;
		case 'W':
			write_record("grade.txt");
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		default:
			printf("Unknown command! \n");
			break;

		}
	}

	a	return 0;

}


void read_record(char *fname)
{

	printf("Reading record from grade.txt...\n");
	printf("4 records have read.\n\n");

	int i = 0;
	FILE *ifp = fopen(fname, "r");
	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
		i++;

	num_record = i;
	fclose(ifp);
}

void print_record()
{
	printf("\n------------------------------\n");
	printf("      %s %d %s\n", r[0].name, r[0].id, r[0].grade);
	printf("      %s %d %s\n", r[1].name, r[1].id, r[1].grade);
	printf("      %s %d %s\n", r[2].name, r[2].id, r[2].grade);
	printf("      %s %d %s\n", r[3].name, r[3].id, r[3].grade);
	printf("------------------------------\n");
}

void search_record()
{
	printf("\n Search name: ");
	char name[30];
	gets(name);

	if (!strcmp(r[0].name, name))
	{
		printf("Name : %s\n", r[0].name);
		printf("ID   : %d\n", r[0].id);
		printf("Grade: %s\n", r[0].grade);
	}
	else if (!strcmp(r[1].name, name))
	{
		printf("Name : %s\n", r[1].name);
		printf("ID   : %d\n", r[1].id);
		printf("Grade: %s\n", r[1].grade);
	}

	else if (!strcmp(r[2].name, name))
	{
		printf("Name : %s\n", r[2].name);
		printf("ID   : %d\n", r[2].id);
		printf("Grade: %s\n", r[2].grade);
	}

	else if (!strcmp(r[3].name, name))
	{
		printf("Name : %s\n", r[3].name);
		printf("ID   : %d\n", r[3].id);
		printf("Grade: %s\n", r[3].grade);
	}
	else
		printf("이름을 찾지 못했습니다.\n 올바른 이름을 입력하십시오.\n");

}

void change_record()
{
	char Name[30];
	char Grade[10];

	printf("\nName: ");
	gets_s(Name, sizeof(Name));

	if (!(strcmp(Name, r[0].name)))
	{
		printf("Grade: ");
		char *str = strcpy(r[0].grade, gets_s(Grade, sizeof(Grade)));

	}

	else if (!(strcmp(Name, r[1].name)))
	{
		printf("Grade: ");
		char *str = strcpy(r[1].grade, gets_s(Grade, sizeof(Grade)));

	}

	else if (!(strcmp(Name, r[2].name)))
	{
		printf("Grade: ");
		char *str = strcpy(r[2].grade, gets_s(Grade, sizeof(Grade)));

	}

	else if (!(strcmp(Name, r[3].name)))
	{
		printf("Grade: ");
		char *str = strcpy(r[3].grade, gets_s(Grade, sizeof(Grade)));

	}

	else
		printf("변경 실패!\n");

	printf("\n Record Changed!\n\n");

}

void write_record(char *fname)
{
	int i = 0;
	FILE *ifp = fopen(fname, "r");
	FILE *ofp = fopen(fname, "w+");

	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
	{

		i++;
	}
}