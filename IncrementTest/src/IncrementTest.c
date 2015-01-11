/*
 ============================================================================
 Name        : IncrementTest.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	int arr[10] = {0};

	for (i = 0; i < 10;)
	{
		arr[i++] = i++;
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}

	return EXIT_SUCCESS;
}


