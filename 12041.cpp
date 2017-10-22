#include <bits/stdc++.h>

using namespace std;

// link: http://uva.onlinejudge.org/external/120/12041.html
// Runtime: 0.080s
// Tag: Recursive, Dp

/*
 * File:   main.cpp
 * Author: shahab
 *
 * Created on August 5, 2011, 8:58 PM
*/

long long fibo[50];
string bfs[50];

void generateFibo()
{
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 50; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}

int bfsOfPosition(int n, long long pos)
{
	if (n < 31)
	{
		return bfs[n][pos] - '0';
	}
	if (pos < fibo[n - 2])
	{
		return bfsOfPosition(n - 2, pos);
	}
	else
	{
		return bfsOfPosition(n - 1, pos - fibo[n - 2]);
	}
}

void generateBfs()
{
	bfs[0] = "0";
	bfs[1] = "1";
	for (int i = 2; i < 31; i++)
	{
		bfs[i] = bfs[i - 2] + bfs[i - 1];
	}
}

int main(int argc, char **argv)
{
	generateFibo();
	generateBfs();
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		long long n, start, end;
		scanf("%lld %lld %lld", &n, &start, &end);
		if (n > 48)
		{
			n = n % 2 ? 47 : 48;
		}
		if (n < 31)
			for (long long i = start; i <= end; i++)
			{
				printf("%c", bfs[n][i]);
			}
		else
			for (long long i = start; i <= end; i++)
			{
				printf("%d", bfsOfPosition(n, i));
			}
		printf("\n");
	}
	return 0;
}
