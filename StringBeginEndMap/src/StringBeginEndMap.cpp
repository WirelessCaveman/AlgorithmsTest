//============================================================================
// Name        : StringBeginEndMap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Given string "4-1;BEGIN-3;3-4;2-END" make sure full path from
//		Begin to End exists
//============================================================================

#include <stdio.h>
#include <stdlib.h>

const int N = 10;

struct mapStr
{
	bool visited;
	char b;
	char e;
};

bool makeMap (char *strg, mapStr *map)
{
	int i = 0;
	bool first = true;
	bool last = false;
	bool foundB = false;
	bool foundE = false;

	while (*strg != '\0')
	{
		switch (*strg)
		{
			case '-':
				strg++;
				if (*strg != '\0') last = true;
				break;
			case ';':
				strg++;
				if (*strg != '\0') first = true;
				break;
		}
		if (first)
		{
			map[i].visited = false;
			map[i].b = *strg;
			if (*strg == 'B') foundB = true;
			first = false;
		}
		else if (last)
		{
			map[i].e = *strg;
			last = false;
			if (*strg == 'E') foundE = true;
			i++;
		}
		strg++;
	}

	if (!(foundB && foundE))
	{
		printf("Begin or End not found %s %s\n", foundB?"Begin":"-", foundE?"End":"-");
		return false;
	}
	return true;
}

bool confirmMap(mapStr *map)
{
	bool ended = false;
	char find = 'B';
	while (!ended)
	{
		int i = 0;
		for (; i < N; ++i)
		{
			if (map[i].b == find)
			{
				if (map[i].visited == true) return false;
				find = map[i].e;
				map[i].visited = true;
				if (map[i].e == 'E') return true;
				break;
			}
		}
		if ((i == N) && (find != map[i].e))
		{
			return false;
		}
	}
	return false;
}

bool doWork(char *strg)
{
	mapStr map[N];
	if (!makeMap(strg, map))
	{
		printf("Not complete map\n");
		return false;
	}
	if (confirmMap(map))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char *myStr = "4-1;Begin-3;3-4;2-End";
	printf("q: %s\n", myStr);
	bool result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	myStr = "4-2;Begin-3;3-4;2-End";
	printf("q: %s\n", myStr);
	result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	myStr = "4-2;1-3;3-4;2-End";
	printf("q: %s\n", myStr);
	result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	myStr = "4-2;Begin-3;3-4;2-5";
	printf("q: %s\n", myStr);
	result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	myStr = "4-2;Begin-3;3-3;2-End";
	printf("q: %s\n", myStr);
	result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	myStr = "4-End;Begin-3;3-4;4-2;2-End";	//This should probably fail
	printf("q: %s\n", myStr);
	result = doWork(myStr);
	printf("Result: %s\n\n", result ? "Good" : "Bad");

	return 0;
}
