//============================================================================
// Name        : TestProject.cpp
// Author      : Shailesh Kadamaje
// Version     :
// Copyright   : Your copyright notice
// Description : Small Test programs
// 1. int WithoutConditions(int a, int b, int c): without using conditional statements, if a != 0, return b, else return c
//============================================================================

#include <stdio.h>
#include <stdlib.h>

int WithoutConditions(int a, int b, int c)
{
//	result = a ? b : c;
//	return ((a/a) * b) + ((1 - (a/a))*c);
	int result;
	(a && (result = b, 1)) || (result = c, 0);
	return result;
}

int main()
{
	printf("WithoutConditions %d\n", WithoutConditions(5, 3,7));
	printf("WithoutConditions %d\n", WithoutConditions(0, 3,7));
	return 0;
}


