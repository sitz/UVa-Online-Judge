#include <bits/stdc++.h>

using namespace std;

int x[1000], y[1000];
int n;
int test(int, int);
int d(int, int);
int main()
{
	int i, j, k, ax;
	for (j = 1;; j++)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d %d ", x + i, y + i);
		}
		ax = 0;
		for (i = 0; i < n; i++)
		{
			ax += test(i, i + 1) + test(i, i + 2);
		}
		printf("Polygon #%d has %d symmetry line(s).\n", j, ax / 2);
	}
}

int test(int a, int b)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		if (d(a, a + n - i) != d(b, b + i))
		{
			return 0;
		}
		if (d(a, b + i) != d(b, a + n - i))
		{
			return 0;
		}
	}
	return 1;
}

int d(int c, int d)
{
	return (x[c % n] - x[d % n]) * (x[c % n] - x[d % n]) + (y[c % n] - y[d % n]) * (y[c % n] - y[d % n]);
}
