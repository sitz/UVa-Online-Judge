#include <bits/stdc++.h>

using namespace std;

int table[300][300];
int f(int, int, int);
inline int g(int a, int b, int z, int x)
{
	int bounda, boundb;
	int max = 0, t;
	if (x > z)
	{
		bounda = (x + z + 1) >> 1, boundb = b;
		if (bounda < a)
		{
			bounda = a;
		}
		max = f(bounda, boundb, x);
		bounda = a;
		boundb = (x + z) >> 1;
		if (boundb > b)
		{
			boundb = b;
		}
		t = f(bounda, boundb, x);
		if (t > max)
		{
			max = t;
		}
	}
	else
	{
		bounda = (x + z + 1) >> 1, boundb = b;
		if (bounda < a)
		{
			bounda = a;
		}
		max = f(bounda, boundb, x);
		bounda = a, boundb = (x + z) >> 1;
		if (boundb > b)
		{
			boundb = b;
		}
		t = f(bounda, boundb, x);
		if (t > max)
		{
			max = t;
		}
	}
	return 1 + max;
}
int f(int a, int b, int z)
{
	if ((a == b && b == z) || (a > b))
	{
		return 0;
	}
	if (a == b)
	{
		return 1;
	}
	int t1 = b - a, t2 = z - a;
	if (t2 < 0)
	{
		t2 = t1 - t2;
	}
	if (table[t1][t2])
	{
		return table[t1][t2];
	}
	int min = 999999;
	for (int x = a; x <= b; x++)
	{
		if (x == z)
		{
			continue;
		}
		int t = g(a, b, z, x);
		if (t < min)
		{
			min = t;
		}
	}
	table[t1][t2] = min;
	return min;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1, n)
	{
		int min = 9999999, t;
		for (int i = 1; i <= n; i++)
		{
			t = f(1, n, i) + 1;
			if (t < min)
			{
				min = t;
			}
		}
		printf("%d guess(es) required.\n", min);
	}
}
