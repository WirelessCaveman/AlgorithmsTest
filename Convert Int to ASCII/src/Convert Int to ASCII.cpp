/*
 ============================================================================
 Name        : ConvertIntToASCII.cpp
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Convert Integer to ASCII representation.
 		Given a 16 bit integer, write a function to return a string of
 		characters denoting that integer (similar to sprintf())
 		e.g. if num = 0xBAD1, your string should be "BAD1", else if
 		num = 123, your string should be "0123". remember that string will
 		require atleast a fixed size of 5 chars: 4 for the number + 1 for '\0'
 		in the end
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MASK 0xF
#define NUM_DIGITS (sizeof(unsigned int))

char* convert(unsigned int integer)
{
	int i, nibbleVal;
	char *a = (char *)malloc(sizeof (char) * (NUM_DIGITS + 1));
	for (i= (NUM_DIGITS - 1); i>=0; i--)
	{
		nibbleVal = (integer & (MASK << (i * 4))) >> (i * 4);

		char nibbleChar;
		if ((nibbleVal >= 0) && (nibbleVal <= 9))
		{
			nibbleChar = '0' + nibbleVal;
		}
		if ((nibbleVal >= 0XA) && (nibbleVal <= 0xF))
		{
			nibbleChar = 'A' + (nibbleVal - 0xA);
		}

		a[NUM_DIGITS-i-1] = nibbleChar;

	}
	a[NUM_DIGITS] = '\0';
	return a;
}

int main(void) {
	int num = 0xABCD;
	printf("The number is %X\n",num);

	printf("the characters in the number are %s",convert(num));
	return 0;
}
