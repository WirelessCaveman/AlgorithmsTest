//============================================================================
// Name        : StringWordReverse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

//"this is a string"
//"gnirts a si siht"
//"string a is this"
//
// Reverse the order of the words, "in-place"
// Large strings, no hard-code limit
// No c-runtime library

void Reverse(char *string)
{
	char *start = string;
	char *end = string;

	while (*(end++)) {}
	end -= 2;	//go to '\0' and then 'g'

	// Reverse entire string
	while (start < end)
	{
		char temp = *start;
		*(start++) = *end;
		*(end--) = temp;
	}

	start = string;
	end = string;

	while (true)
	{
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		end--;

		while (start < end)
		{
			char temp = *start;
			*(start++) = *end;
			*(end--) = temp;
		}

		while (*start != ' ' && *start != '\0')
		{
			start++;
		}
		if (*start == '\0') break;
		start++; //space
		end = start;
	}
}



int main()
{
//	char *testString = "This is a string";	//Bad
	char testString[] = "This is a string";
	Reverse(testString);
	printf("%s\n", testString);

	cout << "StringWordReverse\n" << endl; // prints BitBanging
	return 0;
}
