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
	while (fscanf(ifp, "%s %s", key, data) == 2) 
	{ // (key data)를 읽어 해시테이블에 삽입
		//……………………….
	}
	fclose(ifp);
	return(i);
}

int hash(char *key)
{
	return (transform(key) % TABLE_SIZE);
}

void hash_insert(char *key, char *data)
{
	int hash_value;
	int h = hash_value = hash(key);
	
	while (strlen(hash_table[h].key) != 0)
	{
		if (strcmp(hash_table[h].key, key) == 0)
		{
			printf("duplication");
			return;
		}
		h = (h + 1) % TABLE_SIZE;
		if (h == hash_value)
		{
			printf("table full");
			return;
		}
	}
	strcpy(hash_table[h].key, key);
	strcpy(hash_table[h].data, data);
}

char * hash_search(char *key)
{
	int hash_value;
	int h = hash_value = hash(key);

	while (strlen(hash_table[h].key) != 0)
	{
		if (strcmp(hash_table[h].key, key) == 0)
		{
			printf("location = %d", i);
			return;
		}
	}
	
	h = (h + 1) % TABLE_SIZE;

	if (h == hash_value)
	{
		printf("fali");
		return;
	}

	printf("fail");
}

int transform(char *key)
{
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}

void hash_show()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("hash_table[i] : ", i);
	}
}