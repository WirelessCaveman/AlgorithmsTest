//============================================================================
// Name        : ArrIndexEqVal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Find in an sorted, non repeated array where the index is
//		equal to its data. Both non recursive and recursive solutions.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int NUM_INDEX = 10;
int ARR[NUM_INDEX] = {-6, -2, -1, 0, 3, 4, 6, 10, 11, 15};
int *InArr = ARR;


int FindArrIndexEqValRec(int *arr, int front, int back)
{
	assert (front <= back);
	int middle = (front + back) / 2;
	if (arr[middle] == (middle)) return (middle);
	else if (front == back)
	{
		return -1;
	}
	else
	{
		int result = -1;
		if (arr[middle] < middle)
		{
			result = FindArrIndexEqValRec(arr, middle+1, back);
			if (result != -1) return result;
		}
		else
		{
			result = FindArrIndexEqValRec(arr, 0, middle-1);
			if (result != -1) return result;
		}
	}
	return -1;
}

int FindArrIndexEqVal(int *arr, int size)
{
	assert (arr != NULL);
	int start = 0;
	int end = size - 1;
	while (end >= start)
	{
		int mid = (start + end) / 2;
		if (mid == arr[mid]) return mid;
		else if (mid > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}

int main()
{
	printf("Array: ");
	for (int i = 0; i < NUM_INDEX; ++i)
	{
		printf("[%d] %d, ", i, ARR[i]);
	}
//	printf("\nFindArrIndexEqVal : %d\n", FindArrIndexEqValRec(InArr, 0, 9));
	printf("\nFindArrIndexExVal : %d\n", FindArrIndexEqVal(InArr, 10));
	return 0;
}
