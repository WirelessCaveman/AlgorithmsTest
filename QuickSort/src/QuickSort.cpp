//============================================================================
// Name        : QuickSort.cpp
// Author      : Wireless Caveman
// Version     :
// Copyright   : Your copyright notice
// Description : QuickSort
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void QuickSort(int *arr, int size)
{
	if (size <= 1) return;

	int pivot = arr[size - 1];
	int front = 0;
	int back = 0;
	int tmp = 0;

	while ((arr[back] < pivot) && (back < (size - 1))) {back++;}
	front = back;
	while(front < size - 1)
	{
		if (arr[front] <= pivot)
		{
			tmp = arr[front];
			arr[front] = arr[back];
			arr[back++] = tmp;
		}
		++front;
	}
	tmp = arr[size - 1];
	arr[size - 1] = arr[back];
	arr[back] = tmp;

//	for(int i = 0; i < size; ++i)
//	{
//		printf("%d\t", arr[i]);
//	}
//	printf("\n");

	QuickSort(arr, back);
	QuickSort(&(arr[back + 1]), size - (back + 1));
}

int main()
{
	int arr[10] = {-8, 7, 5, 8, 9, 0, 1, 0, -8, 10};
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	QuickSort(arr, sizeof(arr)/sizeof(int));

	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
