#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "FileIO.h"

void read_txt(char *fname)
{
	FILE *fp = fopen(fname, "r");
	char my_sentence[100];

	if (fp == NULL)
		perror("Error opening file");
	else
	{
		while (fgets(my_sentence, 100, fp))
		{
			if (strlen(my_sentence) != 1)
			{
				puts(my_sentence);
			}
		}
	}
	fclose(fp);
}

