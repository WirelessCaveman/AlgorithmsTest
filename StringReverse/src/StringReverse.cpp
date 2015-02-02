//============================================================================
// Name        : StringReverse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Reverse String
//			string_reverse1: reverses existing string
//			string_reverse2: points to a new string in new memory
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

void string_reverse1(char * string)
{
	char *start = string;
	char *end = string;
	while (*(end++)){}
	end -= 2;
	while (start < end)
	{
		char tmp = *start;
		*(start++) = *end;
		*(end--) = tmp;
	}
}

char * string_reverse2(const char * string)
{
	int count = 0;
	while (*(string + (count++)));

	char *new_string = (char *)malloc(sizeof(char) * count);
	char *new_string_it = new_string;

	count -= 2;
	while(count >= 0)
	{
		*(new_string_it++) = *(string + (count--));
	}
	*new_string_it = '\0';
	return new_string;
}

int main()
{
//	char *string = "abcd efg hij klm";	//bad
	char string[] = "abcd efg hij klm";
//	char string[] = "";
	string_reverse1(string);
	printf("\n%s", string);
	printf("\n%s", string_reverse2(string));
	return 0;
}
