//#include <stdio.h>
//#include "sorting.h"
//
//
//void copy_list(int original[], int list[], int n)
//{
//	for (int i = 0; i<n; i++)
//		list[i] = original[i];
//}
//void print_list(int list[], int left, int right)
//{
//	for (int i = 0; i<left; i++)
//		printf(" ");
//	for (int i = left; i <= right; i++)
//		printf("%4d", list[i]);
//	printf("\n");
//}
//
//void insertion_sort(int list[], int n)
//{
//	int i, j;
//	for (i = 1; i < n; i++)
//	{
//		int next = list[i];
//		for (j = i - 1; j >= 0 && next < list[j]; j--)
//		{	
//			num_compare++;
//			list[j + 1] = list[j];
//		}
//		list[j + 1] = next;
//	}
//}
//
//void quick_sort(int list[], int left, int right)
//{
//	int i, j;
//	if (left < right)
//	{
//		num_compare++;
//		int pivot = partition(list, left, right);
//
//		quick_sort(list, left, pivot - 1);
//		quick_sort(list, pivot + 1, right);
//	}
//}
//
//int partition(int list[], int left, int right)
//{
//	int i = left, j = right + 1, temp = 0;
//	//pivot보다 작은 것과 큰 것으로 나눔
//	int pivot = list[left];
//	while (i < j)
//	{
//		while (list[++i] < pivot);
//		while (list[--j] > pivot);
//		if (i < j)
//			swap(list[i], list[j], temp);
//	}
//
//	//pivot을 중간(j)에 놓고 인덱스 j를 반환
//	swap(list[left], list[j], temp);
//
//	return j;
//}
//
//void swap(int *a, int *b, int tmp)
//{
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void merge_sort(int list[], int left, int right)
//{
//	if (left < right)
//	{
//		num_compare++;
//		int mid = (left + right) / 2;
//
//		merge_sort(list, left, right);
//		merge_sort(list, mid + 1, right);
//		merge(list, left, mid, right);
//	}
//}
//
//void merge(int list[], int left, int mid, int right)
//{
//	int i = left, j = mid + 1, k = left;
//	int sorted[sizeof(original)];
//
//	while (i <= mid && j <= right)
//	{
//		if (list[i] <= list[j]) sorted[k++] = list[i++];
//		else sorted[k++] = list[j++];
//	}
//	if (i > mid)
//		for (int n = j; n <= right; n++)
//			sorted[k++] = list[n];
//	else
//		for (int n = i; n < mid; n++)
//			sorted[k++] = list[n];
//
//	for (int n = left; n <= right; n++)
//		list[n] = sorted[n];
////}