#include <stdio.h>
#include "sorting.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void main()
{
	int list[MAX_SIZE], n = MAX_SIZE;
	printf("\n ----- insertion sort ----- \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	insertion_sort(list, n);
	printf("\n");
	print_list(list, 0, n - 1);
	printf("\n Total number of comparison = %d \n", num_compare);
	
	printf("\n ----- quick sort ----- \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	quick_sort(list, 0, n - 1);
	printf("\n");
	print_list(list, 0, n - 1);
	printf("\n Total number of comparison = %d \n", num_compare);
	
	printf("\n ----- merge sort ----- \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	merge_sort(list, 0, n - 1);
	printf("\n");
	print_list(list, 0, n - 1);
	printf("\n Total number of comparison = %d \n", num_compare);
}

void copy_list(int original[], int list[], int n)
{
	for (int i = 0; i<n; i++)
		list[i] = original[i];
}
void print_list(int list[], int left, int right)
{
	for (int i = 0; i<left; i++)
		printf("    ");
	for (int i = left; i <= right; i++)
		printf("%4d", list[i]);
	printf("\n");
}

void insertion_sort(int list[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int next = list[i];
		print_list(list, 0, n - 1);
		for (j = i - 1; j >= 0 && next < list[j]; j--)
		{
			num_compare++;
			list[j + 1] = list[j];	
		}
		list[j + 1] = next;
	}
}

void quick_sort(int list[], int left, int right)
{
	int i, j;
	
	if (left < right)
	{
		int j = partition(list, left, right);
		
		quick_sort(list, left, j - 1);
		
		quick_sort(list, j + 1, right);
	}
}

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int i, j;
	i = left;
	j = right + 1;
	
	pivot = list[left];
	
	while (i < j)
	{

		while (list[++i] < pivot)
		{
			num_compare++;
		}
		while (list[--j] > pivot)
		{
			num_compare++;
		}
		if (i < j)
		{
			SWAP(list[i], list[j], temp);
		}
		
	}
	
	SWAP(list[left], list[j], temp);
	print_list(list, left, right);

	return j;
}


void merge_sort(int list[], int left, int right)
{
	int mid;
	
	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		
		merge(list, left, mid, right);
	}
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, n;
	i = left, j = mid + 1, k = left;
	
	int sorted[sizeof(original)] = { 0 };

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			num_compare++;
			sorted[k++] = list[i++];		
		}
		else
		{
			num_compare++;
			sorted[k++] = list[j++];		
		}
		
	}
	if (i > mid)
	{
		for (n = j; n <= right; n++)
		{
			sorted[k++] = list[n];		
		}
	}
	else
	{
		for (n = i; n <= mid; n++)
		{
			sorted[k++] = list[n];
		}
	}

	for (n = left; n <= right; n++)
	{
		list[n] = sorted[n];
	}
	print_list(list, left, right);

}