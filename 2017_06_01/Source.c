#include <stdio.h>
#include "hash_dictionary.h"

int build_dictionary(char *fname)
{
	int i = 0; // ������ ��
	char key[100], data[200];
	FILE *ifp;
	if ((ifp = fopen(fname, "r")) == NULL) {
		printf("No such file ! \n");
		exit(1);
	}
	while (fscanf(ifp, "%s %s", key, data) == 2) { // (key data)�� �о� �ؽ����̺� ����
		//������������������.
	}
	fclose(ifp);
	return(i);
}