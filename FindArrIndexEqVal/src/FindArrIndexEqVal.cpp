//============================================================================
// Name        : ArrIndexEqVal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Find in an array where the index is equal to its data
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int NUM_INDEX = 10;
int ARR[NUM_INDEX] = {-6, -2, -1, 0, 3, 5, 9, 10, 11, 15};
int *InArr = ARR;


int FindArrIndexEqVal(int *arr, int front, int back)
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
			result = FindArrIndexEqVal(arr, middle+1, back);
			if (result != -1) return result;
		}
		else
		{
			result = FindArrIndexEqVal(arr, 0, middle-1);
			if (result != -1) return result;
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
	printf("\nFindArrIndexEqVal : %d\n", FindArrIndexEqVal(InArr, 0, 9));
	return 0;
}
