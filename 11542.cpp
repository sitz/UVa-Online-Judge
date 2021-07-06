#include <bits/stdc++.h>

using namespace std;

#define MAXN 502

typedef long long LL;

bool vis[MAXN * 50];
int n, m, maxp, prim[MAXN], mat[MAXN][MAXN];

void init()
{
	for (int i = 2; i * i < MAXN * 50; i++)
	{
		for (int j = 2; j * j < MAXN * 50; j++)
		{
			vis[i * j] = true;
		}
	}
	for (int i = 2; m <= 500; i++)
	{
		if (!vis[i])
		{
			prim[++m] = i;
		}
	}
}

void input()
{
	long long x;
	memset(mat, 0, sizeof(mat));
	scanf("%d", &n);
	maxp = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		for (int j = 1; j <= m; j++)
		{
			while (x % prim[j] == 0)
			{
				x /= prim[j];
				mat[j][i] ^= 1;
				if (j > maxp)
				{
					maxp = j;
				}
			}
			if (x == 1LL)
			{
				break;
			}
		}
	}
}

int gauss_jordan()
{
	int row, col, i, j, ret, cnt = 0;
	for (row = col = 1; row <= maxp && col <= n; row++, col++)
	{
		ret = -1;
		for (i = row; i <= maxp; i++)
		{
			if (mat[i][col])
			{
				ret = i;
				break;
			}
		}
		if (ret == -1)
		{
			row--;
			continue;
		}
		cnt++;
		for (i = 1; i <= n + 1; i++)
		{
			swap(mat[ret][i], mat[row][i]);
		}
		for (i = 1; i <= maxp; i++)
		{
			if (i != row && mat[i][col])
			{
				for (j = n + 1; j >= col; j--)
				{
					mat[i][j] ^= mat[row][j];
				}
			}
		}
	}
	return cnt;
}

int main()
{
	int T;
	init();
	scanf("%d", &T);
	while (T--)
	{
		input();
		int cnt = gauss_jordan();
		long long ans = (1LL << (n - cnt)) - 1;
		printf("%lld\n", ans);
	}
	return 0;
}
