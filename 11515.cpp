#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11515.html
// Runtime : 0.012s
// Tag : math, distance

//============================================================================
// Name        : UVa_11515.cpp
// Author      : Shahab
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

struct crane
{
	int x;
	int y;
	int r;
} a[15 + 3];

int n;

int p2(int x)
{
	return x * x;
}

bool is_conflict(int p)
{
	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & p)// i selected
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((1 << j) & p)// j selected
				{
					int dist = p2(a[i].x - a[j].x) + p2(a[i].y - a[j].y);
					if (dist <= p2(a[i].r + a[j].r))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

int calcArea(int p)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & p)
		{
			ret += p2(a[i].r);
		}
	}
	return ret;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].r);
		}
		int maxi = -1;
		for (int i = 1; i < (1 << n); i++)
		{
			if (!is_conflict(i))
			{
				maxi = max(maxi, calcArea(i));
			}
		}
		printf("%d\n", maxi);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
