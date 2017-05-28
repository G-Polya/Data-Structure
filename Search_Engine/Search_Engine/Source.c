#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "FileIO.h"

void read_tok(char *fname)
{
	char buffer[100];

	FILE *fp = fopen(fname, "r");
	while(fgets(buffer, sizeof(buffer),fp))
	{		
		if (strlen(buffer) != 1)
		{
			char *pch = strtok(buffer, " !,.?\n");

			while (pch != NULL)
			{
				printf("%s\n", pch);
				pch = strtok(NULL, " !,.?\n");
			}
		}
	}
	fclose(fp);
}


//void tok_txt()