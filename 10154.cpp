#include <bits/stdc++.h>

using namespace std;

#define maxn 5610
#define INF 10000000

long n = 0, ans = 0, a[maxn], b[maxn], d[maxn][maxn];

void Qsort(long begin, long end)
{
	long i = begin, j = end, mid = b[(begin + end) / 2], t;
	do
	{
		while (b[i] < mid)
		{
			i++;
		}
		while (b[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			t = b[i];
			b[i] = b[j];
			b[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (begin < j)
	{
		Qsort(begin, j);
	}
	if (i < end)
	{
		Qsort(i, end);
	}
}

int main()
{
	while (scanf("%ld%ld", &a[n + 1], &b[n + 1]) == 2)
	{
		n++;
		b[n] -= a[n];
	}
	//  Read In
	Qsort(1, n);
	//  Sort
	for (long i = 0; i <= n; i++)
		for (long j = 0; j <= n; j++)
		{
			d[i][j] = INF;
		}
	for (long i = 0; i <= n; i++)
	{
		d[i][0] = 0;
	}
	//  Init
	for (long i = 1; i <= n; i++)
		for (long j = 1; j <= i; j++)
		{
			d[i][j] = min(d[i][j], d[i - 1][j]);
			if (d[i - 1][j - 1] <= b[i])
			{
				d[i][j] = min(d[i][j], d[i - 1][j - 1] + a[i]);
			}
		}
	//  DP
	for (long i = n; i >= 1; i--)
		if (d[n][i] < INF)
		{
			ans = i;
			break;
		}
	printf("%ld\n", ans);
	return 0;
}
