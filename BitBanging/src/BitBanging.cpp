//============================================================================
// Name        : BitBanging.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//		Parity: return True for Even parity
//		numBitsSet: return number of set Bits
//============================================================================

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define MASK_16 0xFFFF
#define HALF_BITS 16

bool Parity(unsigned int value)
{
	unsigned int mask = MASK_16;
	unsigned int halfBits = 16;

	while (halfBits && value)
	{
		unsigned int left = value >> halfBits;
		unsigned int right = mask & value;
		value = left ^ right;
		halfBits >>= 1;
		mask >>= halfBits;
	}
	return value;
}

int numBitsSet(int number)
{
	int count = 0;
	while (number)
	{
		++count;
		number &= (number - 1);
	}
	return count;
}


int main()
{
	unsigned int parityVal = 0xAAAA;
	if (Parity(parityVal)) printf("%d has odd parity\n", parityVal);
	else printf("0x%X has even parity\n", parityVal);
	parityVal = 0xd;
	if (Parity(parityVal)) printf("0x%X has odd parity\n", parityVal);
	else printf("%d has even parity\n", parityVal);

	int number = 0x54;
	printf("numBitsSet(0x%X): %d", number, numBitsSet(number));
	return 0;
}
