#include <bits/stdc++.h>

using namespace std;

int A[6], N, B[15], total, max_;

int Sorted(int ss[])
{
	int i;
	for (i = 1; i < N; i++)
	{
		if (ss[i] > ss[i + 1])
		{
			return 0;
		}
	}
	return 1;
}
int Cheack(int level)
{
	int i, t, ss[10], x, y;
	for (i = 1; i <= N; i++)
	{
		ss[i] = A[i];
	}
	for (i = 1; i <= level; i++)
	{
		x = B[i];
		y = x + 1;
		t = ss[x];
		ss[x] = ss[y];
		ss[y] = t;
	}
	return Sorted(ss);
}
void Swap(int x, int y)
{
	int t;
	t = A[x];
	A[x] = A[y];
	A[y] = t;
}
void Recur(int n, int level)
{
	int i, x;
	x = n + 1;
	if (A[x] >= A[n])
	{
		return;
	}
	Swap(n, x);
	if (Sorted(A))
	{
		if (level < max_)
		{
			max_ = level;
			total = 1;
		}
		else
		{
			total++;
		}
	}
	if (level >= max_)
	{
		Swap(n, x);
		return;
	}
	for (i = 1; i < N; i++)
	{
		Recur(i, level + 1);
	}
	Swap(n, x);
}
int Cal()
{
	int i;
	max_ = 10;
	if (N == 1)
	{
		return 0;
	}
	if (Sorted(A))
	{
		return 0;
	}
	total = 0;
	for (i = 1; i < N; i++)
	{
		Recur(i, 1);
	}
	return total;
}

int main()
{
	int i, ks = 1;
	while (scanf("%d", &N) && N)
	{
		if (!N)
		{
			break;
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
		}
		printf("There are %d swap maps for input data set %d.\n", Cal(), ks++);
	}
	return 0;
}
