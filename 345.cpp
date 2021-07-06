#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

int N, A, B, cnt[MAX_N], map_[MAX_N];
double a[MAX_N][MAX_N];

void error()
{
	int um = 1, zero = 0;
	um = um / zero;
}

int search(int k)
{
	int i;
	for (i = 0; i < N; i++)
		if (map_[i] == k)
		{
			return i;
		}
	map_[N] = k;
	N++;
	if (N >= MAX_N)
	{
		error();
	}
	return N - 1;
}

void init()
{
	int i, j;
	for (i = 0; i < MAX_N; i++)
	{
		cnt[i] = 0;
		for (j = 0; j < MAX_N; j++)
		{
			a[i][j] = 0.0;
		}
	}
}

void visit(int start, int deleted, int vis[])
{
	int i, j, x, y;
	int b[MAX_N][MAX_N];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			b[i][j] = 0;
		}
	for (i = 0; i < N; i++)
		if (i != deleted)
			for (j = 0; j < N; j++)
				if (j != deleted && a[i][j] > 0.0)
				{
					b[i][j] = 1;
				}
	for (y = 0; y < N; y++)
		for (x = 0; x < N; x++)
			if (b[x][y])
				for (j = 0; j < N; j++)
					if (b[y][j])
					{
						b[x][j] = 1;
					}
	for (i = 0; i < N; i++)
	{
		vis[i] = b[start][i];
	}
	vis[start] = 1;
	vis[deleted] = 1;
}

int eliminate()
{
	int i, j, c = 0;
	for (i = 0; i < N; i++)
		if (i != A && i != B && cnt[i] == 1)
		{
			// eliminate this
			for (j = 0; j < N; j++)
			{
				if (a[i][j] > 0.0)
				{
					cnt[i]--;
					cnt[j]--;
					a[i][j] = 0.0;
					a[j][i] = 0.0;
					c++;
					if (cnt[i] == 0)
					{
						break;
					}
				}
			}
		}
	return c;
}

void putResistor(int x, int y, double r)
{
	if (r > 0.0)
	{
		if (a[x][y] > 0.0)
		{
			// parallel
			//1/rt = 1/r1 + 1/r2
			a[x][y] = (a[x][y] * r) / (a[x][y] + r);
			a[y][x] = a[x][y];
		}
		else
		{
			cnt[x]++;
			cnt[y]++;
			a[x][y] = r;
			a[y][x] = r;
		}
	}
}

void findRes()
{
	int i, j, x, y;
	int c = 1;
	double r;
	while (c > 0)
	{
		c = 0;
		while (eliminate())
			;
		for (j = 0; j < N; j++)
			if (j != A && j != B && cnt[j] == 2)
			{
				x = -1;
				y = -1;
				for (i = 0; i < N; i++)
					if (i != j && a[i][j] > 0.0)
					{
						if (x < 0)
						{
							x = i;
						}
						else
						{
							y = i;
							break;
						}
					}
				if (y == -1 || x == -1)
				{
					error();
				}
				cnt[x]--;
				cnt[y]--;
				cnt[j] -= 2;
				r = a[x][j] + a[j][y];
				a[x][j] = 0.0;
				a[j][x] = 0.0;
				a[j][y] = 0.0;
				a[y][j] = 0.0;
				putResistor(x, y, r);
				c++;
			}
	}
}

int main()
{
	int i, x, y, k;
	int pn = 0;
	double r;
	while (3 == scanf("%d %d %d", &k, &A, &B))
	{
		N = 0;
		if (k == 0 && A == 0 && B == 0)
		{
			break;
		}
		A = search(A);
		B = search(B);
		init();
		for (i = 0; i < k; i++)
		{
			scanf("%d %d %lf", &x, &y, &r);
			x = search(x);
			y = search(y);
			putResistor(x, y, r);
		}
		findRes();
		printf("Case %d: %.2lf Ohms\n", ++pn,
					 ((int)(a[A][B] * 100 + 0.5)) / 100.0);
	}
	return 0;
}
