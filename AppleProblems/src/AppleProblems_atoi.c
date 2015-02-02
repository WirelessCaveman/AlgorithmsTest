/*
 ============================================================================
 Name        : AppleProblems_atoi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : PROBLEM 1
You may be familiar with the following C function from stdlib.h:
	int atoi(const char * str);
This function parses a C string, interprets its content as an integral
number, then returns this number as an int value. Provide another
implementation of this function (using a different name) along with a small
main() function that demonstrates its use.  Your solution should be a single
C source file that may be compiled using a standard C compiler.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error case could throw an assert, but I return a fault condition
#define FAULT	0xBADBEEF

int MyATOI(char *numStr)
{
	int num = 0;
	int sign = 1;

	if (!(*numStr)) return FAULT;
	else if ('-' == (*numStr))
	{
		sign = -1;
		numStr++;
	}
	else if ('+' == (*numStr))
	{
		sign = 1;
		numStr++;
	}
	//	else
	{
		while (*(numStr))
		{
			if ((*numStr < '0') || (*numStr > '9')) return FAULT;
			num = (num * 10) + (int)((*numStr) - '0');
			numStr++;
		}
	}
	return num * sign;
}

int main(void)
{
	printf("My atoi() implementation:\n");
	char *str = "45";
	printf("%s: %d\n", str, MyATOI(str));
	str = "1002";
	printf("%s: %d\n", str, MyATOI(str));
	str = "";
	printf("%s: %d\n", str, MyATOI(str));
	str = "-0";
	printf("%s: %d\n", str, MyATOI(str));
	str = "+0";
	printf("%s: %d\n", str, MyATOI(str));
	str = "0";
	printf("%s: %d\n", str, MyATOI(str));
	str = "-9";
	printf("%s: %d\n", str, MyATOI(str));
	str = "+9";
	printf("%s: %d\n", str, MyATOI(str));
	str = "9";
	printf("%s: %d\n", str, MyATOI(str));
	str = "8a";
	printf("%s: %d\n", str, MyATOI(str));
	str = "a8";
	printf("%s: %d\n", str, MyATOI(str));
	str = "-12";
	printf("%s: %d\n", str, MyATOI(str));
	str = "+46";
	printf("%s: %d\n", str, MyATOI(str));
	str = ".58";
	printf("%s: %d\n", str, MyATOI(str));
	return EXIT_SUCCESS;
}
