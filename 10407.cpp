#include <bits/stdc++.h>

using namespace std;

int a[1001], dif[1001], p;
int sort_function(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int diff()
{
	int i;
	for (i = 0; i < p - 1; i++)
	{
		dif[i] = abs(a[i + 1] - a[i]);
	}
	return 0;
}
int gsg(int a, int b)
{
	int d, c;
	if (!a && b)
	{
		return b;
	}
	if (a && !b)
	{
		return a;
	}
	if (!a && !b)
	{
		return 0;
	}
	while (1)
	{
		d = b % a;
		if (!d)
		{
			break;
		}
		b = a;
		a = d;
	}
	return a;
}
int result()
{
	int min, i, j, c;
	for (i = 0; i < p - 1; i++)
		if (p == 2)
		{
			return dif[0];
		}
	min = gsg(dif[0], dif[1]);
	if (min == 1)
	{
		return 1;
	}
	for (i = 2; i < p - 1; i++)
	{
		c = gsg(min, dif[i]);
		if (c == 1)
		{
			return 1;
		}
		min = c;
	}
	return min;
}
int main()
{
	p = 0;
	while (scanf("%d", &a[p]) && a[p])
	{
		p++;
		while (scanf("%d", &a[p]) && a[p])
		{
			p++;
		}
		qsort((void *)a, p, sizeof(int), sort_function);
		diff();
		printf("%d\n", result());
		p = 0;
	}
	return 0;
}
