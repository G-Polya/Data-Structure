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