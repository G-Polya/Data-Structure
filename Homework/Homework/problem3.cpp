#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void swap(int *a, int *b);
void selection_sort(int list[], int n);

int main()
{

	//�迭�� ���� �Է�
	int list[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		list[i] = rand();

	float start = clock();							//���� �ð�
	selection_sort(list, MAX);
	float end = clock();							//����ð�
	float computation_time = (float)(end - start) / (float) 1000;			//elapsed_time = end - start

	printf("computatin_time at %d: %.4f��\n", MAX, computation_time);
	return 0;

}

//swap function
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//seclection_sort, time_complexity: O(n^2)
void selection_sort(int list[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(&list[i], &list[min]);
	}
}