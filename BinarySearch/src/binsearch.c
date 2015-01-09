/*
 ============================================================================
 Name        : binsearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Binary search
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int binsearch_nonrec(int arr[], int find, int len)
{
	int start = 0, end = len-1;
	while (end >= start)
	{
		int split = (start + end)/2;
		if (arr[split] == find) return split;
		else
		{
			if (arr[split] > find)
			{
				end = split - 1;
			}
			else	//if arr[split] < find
			{
				start = split + 1;
			}
		}

	}
	return -1;
}

int binsearch_rec (int arr[], int find, int len)
{
	int start = 0, end = len - 1;
	static int found = -1;
	if (start < end)
	{
		int mid = len / 2;
		if (arr[mid] == find)
		{
			found = mid;
			return found;
		}
		else if (find < arr[mid])
		{
			binsearch_rec(&(arr[0]), find, mid);
		}
		else
		{
			binsearch_rec(&(arr[mid]), find, len-mid);
			if (found != -1) found += mid;
		}
	}
	else if ((start >= end) && (arr[end] == find)) found = end;
	return found;
}

int main(void)
{
	int array[7] = {-3, 4, 4, 6, 21, 22, 22};
	int find  = 7;
	printf("NonRec found %d at %d\n", find, binsearch_nonrec(array, find, 7));
	printf("Recursive found %d at %d\n", find, binsearch_rec(array, find, 7));
	return EXIT_SUCCESS;
}
