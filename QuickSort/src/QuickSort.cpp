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

void QuickSort_FrontBack(int *arr, int size)
{
	if (size <= 1) return;

	int pivot = arr[size - 1];
	int front = size - 2;
	int back = 0;
	int tmp = 0;

	while(back < front)
	{
		while((front > back) && (arr[back] <= pivot)) {back++;}
		while((front > back) && (arr[front] >= pivot)) {front--;}
		if (arr[back] > arr[front])
		{
			tmp = arr[back];
			arr[back] = arr[front];
			arr[front] = tmp;
		}
	}
	if ((arr[front] < pivot) && (front < size - 1)) front++;
	if (arr[front] > arr[size - 1])
	{
		tmp = arr[front];
		arr[front] = arr[size - 1];
		arr[size - 1] = tmp;
	}

	for(int i = 0; i < size; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	QuickSort_FrontBack(arr, front);
	QuickSort_FrontBack(&(arr[front+1]), size - (front + 1));
}

void QuickSort_OneDirection(int *arr, int size)
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

	QuickSort_OneDirection(arr, back);
	QuickSort_OneDirection(&(arr[back + 1]), size - (back + 1));
}

int main()
{
	int arr[10] = {-8, 7, 5, 8, 9, 0, 1, 0, -8, 10};
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

//	QuickSort_OneDirection(arr, sizeof(arr)/sizeof(int));
	QuickSort_FrontBack(arr, sizeof(arr)/sizeof(int));

	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
