#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "hash_dictionary.h"

int build_dictionary(char *fname)
{
	int i = 0; // 데이터 수
	char key[100], data[200];
	FILE *ifp = fopen(fname, "r");
	if (ifp == NULL) {
		printf("No such file ! \n");
		exit(1);
	}
	while (fscanf(ifp, "%s %s", key, data) == 2) 
	{ // (key data)를 읽어 해시테이블에 삽입
		hash_insert(key, data);
		i++;
	}
	fclose(ifp);
	return (i);
}

int hash(char *key)
{
	return (transform(key) % TABLE_SIZE);
}

//해시테이블에 특정 key를 가지는 data삽입
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
		}	//중복

		h = (h + 1) % TABLE_SIZE;
		if (h == hash_value)
		{
			printf("table full");
			return;
		}
	}

	//삽입
	strcpy(hash_table[h].key, key);
	strcpy(hash_table[h].data, data);
}

//특정 key에 해당하는 data 찾기
char* hash_search(char *key)
{
	int hash_value;
	int h = hash_value = hash(key);

	while (strlen(hash_table[h].key) != 0)
	{
		num_comparison++;
		if (strcmp(hash_table[h].key, key) == 0)	//내가 찾는 key(parameter로 받아온 key)가 해시테이블의 key에 있다면
		{
			printf("Hash Value = %d", hash_value);
			
			return hash_table[h].key;
		}
		h = (h + 1) % TABLE_SIZE;

		if (h == hash_value)
		{
			printf("fail");
			return ;
		}

	}

	printf("fail");

	return NULL;
}

//문자열인 key를 int형으로 transform
int transform(char *key)
{
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}

//해시테이블을 보여줌
void hash_show()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("hash_table[%d] : <%s>\n", i, hash_table[i].key);
	}
}