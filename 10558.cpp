#include <bits/stdc++.h>

using namespace std;

#define MAXD 110
int N, S, A, g[MAXD][MAXD], f[MAXD][MAXD], street[MAXD];
int t[MAXD][MAXD], st[MAXD][MAXD][MAXD], s[MAXD][MAXD], p[MAXD][MAXD];
int init()
{
	int i, j, k, flag, x, y;
	scanf("%d", &N);
	if (N == -1)
	{
		return 0;
	}
	memset(g, 0, sizeof(g));
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &y, &x);
		g[x][y] = 1;
	}
	scanf("%d", &S);
	for (i = 0; i < S; i++)
	{
		scanf("%d", &street[i]);
	}
	scanf("%d", &A);
	memset(t, 0, sizeof(t));
	for (i = 2; i <= 100; i++)
		for (j = 1; j < S; j++)
		{
			flag = 0;
			for (k = street[j - 1]; k < street[j]; k++)
				if (g[i - 1][k])
				{
					flag = 1;
				}
			if (flag)
			{
				t[i][j] = 1;
			}
		}
	memset(s, 0, sizeof(s));
	memset(st, 0, sizeof(st));
	for (i = 1; i < 100; i++)
		for (j = i + 1; j <= 100; j++)
		{
			for (k = 1; k < S; k++)
			{
				st[i][j][k] |= st[i][j - 1][k];
			}
			for (k = 1; k < S; k++)
			{
				st[i][j][k] |= t[j][k];
			}
			for (k = 1; k < S; k++)
				if (st[i][j][k])
				{
					s[i][j]++;
				}
		}
	return 1;
}
void printpath(int i, int k)
{
	if (k != 1)
	{
		printpath(i - 1, p[i][k]);
	}
	printf(" %d", k);
}
void solve()
{
	int i, j, k, max;
	memset(f, -1, sizeof(f));
	for (i = 2; i <= 100; i++)
	{
		f[1][i] = s[1][i];
		p[1][i] = 1;
	}
	for (i = 2; i < A; i++)
		for (j = i + 1; j <= 100; j++)
		{
			for (k = i; k < j; k++)
				if (f[i - 1][k] + s[k][j] > f[i][j])
				{
					f[i][j] = f[i - 1][k] + s[k][j];
					p[i][j] = k;
				}
		}
	printf("%d", A);
	printpath(A - 1, 100);
	printf("\n");
}
int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
