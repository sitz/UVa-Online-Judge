#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/118/11889.html
// Runtime : 0.320s
// Tag : Prime Factors, LCM

//===============================================================
// Name        : UVa_11889.cpp
// Author      : Shahab
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//===============================================================

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

bool mark[N];
vector<int> primeList;

void seive()
{
	memset(mark, true, sizeof(mark));
	mark[0] = mark[1] = false;
	for (int i = 4; i < N; i += 2)
	{
		mark[i] = false;
	}
	for (int i = 3; i * i <= N; i += 2)
	{
		if (mark[i])
		{
			for (int j = i * i; j < N; j += 2 * i)
			{
				mark[j] = false;
			}
		}
	}
	primeList.clear();
	primeList.push_back(2);
	for (int i = 3; i < N; i += 2)
	{
		if (mark[i])
		{
			primeList.push_back(i);
		}
	}
}

int power(int a, int b)
{
	int ret = 1;
	for (int i = 1; i <= b; i++)
	{
		ret *= a;
	}
	return ret;
}

int factors(int a, int b)
{
	int ret = 1;
	int in = 0;
	int tmp = a;
	while (primeList[in] * primeList[in] <= tmp)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		while (a % primeList[in] == 0)
		{
			a /= primeList[in];
			cnt1++;
		}
		while (b % primeList[in] == 0)
		{
			b /= primeList[in];
			cnt2++;
		}
		if (cnt1 > cnt2)
		{
			ret *= power(primeList[in], cnt1);
		}
		in++;
	}
	if (a > 1 && b == 1)
	{
		ret *= a;
	}
	return ret;
}

int main()
{
	seive();
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int a, c;
		scanf("%d %d", &a, &c);
		if (c % a == 0)
		{
			printf("%d\n", factors(c, a));
		}
		else
		{
			printf("NO SOLUTION\n");
		}
	}
	return 0;
}

// @END_OF_SOURCE_CODE
