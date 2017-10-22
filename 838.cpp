#include <bits/stdc++.h>

using namespace std;

#define out 1005

int X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
int B[15][15], U[1010], W[1010], max_, len, total, ab;

void traverse(int x, int y)
{
	if (len + total <= max_)
	{
		return;
	}
	if (U[B[x][y]])
	{
		return;
	}
	len++;
	U[B[x][y]] = 1;
	total -= W[B[x][y]];
	if (len > max_)
	{
		max_ = len;
	}
	int i;
	for (i = 0; i < 4; i++)
	{
		traverse(x + X[i], y + Y[i]);
	}
	total += W[B[x][y]];
	U[B[x][y]] = 0;
	len--;
}

int main()
{
	int t, first = 1, n, i, j;
	U[out] = 100000;
	for (i = 0; i <= 15; i++)
	{
		B[0][i] = B[i][0] = out;
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i <= 1000; i++)
		{
			W[i] = U[i] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			B[i][n + 1] = B[n + 1][i] = out;
		}
		ab = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &B[i][j]);
				if (W[B[i][j]] == 0)
				{
					ab++;
				}
				W[B[i][j]]++;
			}
		}
		max_ = 0;
		total = n * n;
		for (i = 1; i <= n && max_ != ab; i++)
		{
			for (j = 1; j <= n && max_ != ab; j++)
			{
				len = 0;
				traverse(i, j);
			}
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		printf("%d\n", max_);
	}
	return 0;
}
