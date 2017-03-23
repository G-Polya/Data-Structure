#include <stdio.h>
#include "Matrix.h"

int main()
{
	int a[ROW][COL] = { { 1,0,0 },{ 1,0,0 },{ 1,0,0 } };
	int b[ROW][COL] = { { 1,1,1 },{ 0,0,0 },{ 0,0,0 } };
	int c[ROW][COL] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };

	/*matrix_print(a);
	printf("\n");
	matrix_print(b);
	printf("\n");
	matrix_print(c);
	printf("\n");
*/
	matrix_print(a);
	printf("\n");
	matrix_print(b);
	matrix_add(a, b, c);
	
	matrix_print(c);
	matrix_init(c);
	matrix_mult(a, b, c);
	matrix_print(c);
	
	matrix_init(c);
	matrix_transpose(a, c);
	matrix_print(c);

	return 0;
}

void matrix_init(int a[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			a[i][j] = 0;
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL])
{
	printf("\na + b = \n");
	for(int i = 0; i<ROW;i++)
		for (int j = 0; j < COL; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
}

void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL])
{
	printf("\na * b = \n");
	for (int i = 0; i < ROW; i++)		//i x k
	{
		for (int j = 0; j < COL; j++)	// k x j
		{
			for (int k = 0; k < COL; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}


void matrix_transpose(int a[ROW][COL],int c[ROW][COL])
{
	printf("\na transpose = \n");

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			c[i][j] = a[j][i];

}



void matrix_print(int a[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

