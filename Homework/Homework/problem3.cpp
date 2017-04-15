#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void swap(int* a, int* b);
void selection_sort(int list[], int n);

int main()
{
	int list[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		list[i] = rand();

	float start = clock();
	selection_sort(list, MAX);
	float end = clock();
	float computation_time = (float)(end - start) / 1000;

	printf("computatin_time at %d: %f\n", MAX, computation_time);
	return 0;

}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int list[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(&list[i], &list[min]);
	}
}