#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "hash_dictionary.h"

int build_dictionary(char *fname)
{
	int i = 0; // 데이터 수
	char key[100], data[200];
	FILE *ifp;
	if ((ifp = fopen(fname, "r")) == NULL) {
		printf("No such file ! \n");
		exit(1);
	}
	while (fscanf(ifp, "%s %s", key, data) == 2) { // (key data)를 읽어 해시테이블에 삽입
		//……………………….
	}
	fclose(ifp);
	return(i);
}

int hash(char *key)
{
	return (*key % 100);
}

void hash_insert(char *key, char *data)
{
	int h = hash(key);
	int i = 0;

	while (hash_table[h].key != 0 && (i < 100))
	{
		if (hash_table[h].key == key)
		{
			strcpy(hash_table[h].data,data);
			return;
		}
		h = (h + 1) % 100;
		i++;
	}

	if (hash_table[h].key == 0)
	{
		strcpy(hash_table[h].key, key);
		strcpy(hash_table[h].data, data);
	}

}

char * hash_search(char *key)
{
	int h = hash(key);

	while (hash_table != NULL)
	{
		if (hash_table[h].key == key)
			return hash_table;
	}


}