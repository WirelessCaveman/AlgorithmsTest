//============================================================================
// Name        : MinCoinsForChange.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : http://codercareer.blogspot.com/2011/12/no-26-minimal-number-of-coins-for.html
// function which gets the minimal number of coins, whose value is v1, v2, …, vn, to make change for an amount of money with value t.
// Any coin with value vi may duplicate for any times to make change.
// For example, the minimal number of coins to make change for 15 out of a set of coins with value 1, 3, 9, 10 is 3.
// We can choose two coins with value 3 and a coin with value 9. The number of coins for other choices should be greater than 3
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int NUM_COINS = 4;
const int COINS[NUM_COINS] = {1, 3, 9, 10};

int MinFxn(int a, int b)
{
	return (a < b ? a : b);
}

int MinCoinsForChangeRecursive(int val, int *arr)
{
	assert(val > 0);
	if (arr[val] != -1) return arr[val];

	int count = val;
	for (int i = 0; i < NUM_COINS; ++i)
	{
		if (val >= COINS[i])
		{
			count = MinFxn(count, 1 + MinCoinsForChangeRecursive(val - COINS[i], arr));
		}
	}
	arr[val] = count;
	return count;
}

int MinCoinsForChangeRecursiveWrap(int val)
{
	int arr[val + 1];	//how is this working?
	arr[0] = 0;
	int coin = 0;
	for (int i = 1; i <= val; ++i)
	{
		if (COINS[coin] == i)
		{
			arr[i] = 1;
			if (coin < NUM_COINS) coin++;
		}
		else arr[i] = -1;
	}
	int minCoins = MinCoinsForChangeRecursive(val, arr);
	return minCoins;
}

int MinCoinsForChangeIterative(int val)
{
	assert(val >= 0);
	int arr[val + 1];	//how is this working?
	arr[0] = 0;

	for (int i = 1; i <= val; ++i)
	{
		int count = i;
		for (int j = NUM_COINS - 1; j >= 0; --j)
		{
			if ((i >= COINS[j]) && (count > (1 + arr[i - COINS[j]])))
			{
				count = 1 + arr[i - COINS[j]];
			}
		}
		arr[i] = count;
	}
	return arr[val];
}

int main()
{
	printf("Min coins to get exact change (rec): %d\n", MinCoinsForChangeRecursiveWrap(16));
	printf("Min coins to get exact change (iter): %d\n", MinCoinsForChangeIterative(16));
	return 0;
}
