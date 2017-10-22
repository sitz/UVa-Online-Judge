#include <bits/stdc++.h>

using namespace std;

#define MAXD 30

int L, N, W, s[MAXD], r1[MAXD], r2[MAXD], N1, N2, x[MAXD], w[MAXD], vis[MAXD];

int cmp(const void *_p, const void *_q)
{
	int *p = (int *)_p;
	int *q = (int *)_q;
	int x1, x2;
	if (x[*p] < 0)
		x1 = (-3 - x[*p]) * w[*p];
	else
		x1 = (x[*p] - 3) * w[*p];
	if (x[*q] < 0)
		x2 = (-3 - x[*q]) * w[*q];
	else
		x2 = (x[*q] - 3) * w[*q];
	return x1 - x2;
}

void init()
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &x[i], &w[i]);
		x[i] *= 2;
	}
}

int dfs(int left, int right, int num)
{
	int i, j, k, t, flag, mleft, mright, tleft = 1, tright = 1;
	if (num == N)
		return 2;
	for (i = 0; i < N1; i++)
	{
		k = r1[i];
		if (!vis[k])
		{
			vis[k] = 1;
			mleft = left + (x[k] + 3) * w[k], mright = right + (3 - x[k]) * w[k];
			s[num] = k;
			if (mleft >= 0)
				tleft = 0;
			if (mleft >= 0 && mright >= 0)
			{
				flag = dfs(mleft, mright, num + 1);
				if (flag == 2)
					return 2;
				if (flag == -1)
					break;
				tleft = 0;
			}
			vis[k] = 0;
		}
	}
	for (i = 0; i < N2; i++)
	{
		k = r2[i];
		if (!vis[k])
		{
			vis[k] = 1;
			mleft = left + (x[k] + 3) * w[k], mright = right + (3 - x[k]) * w[k];
			s[num] = k;
			if (mright >= 0)
				tright = 0;
			if (mleft >= 0 && mright >= 0)
			{
				flag = dfs(mleft, mright, num + 1);
				if (flag == 2)
					return 2;
				if (flag == 1)
					break;
				tright = 0;
			}
			vis[k] = 0;
		}
	}
	return tright - tleft;
}
void solve()
{
	int i, j, k, left, right, num;
	memset(vis, 0, sizeof(vis));
	num = 0;
	left = right = 3 * W;
	for (i = 0; i < N; i++)
		if (x[i] >= -3 && x[i] <= 3)
		{
			s[num++] = i;
			vis[i] = 1;
			left = left + (x[i] + 3) * w[i], right = right + (3 - x[i]) * w[i];
		}
	N1 = N2 = 0;
	for (i = 0; i < N; i++)
		if (!vis[i])
		{
			if (x[i] < 0)
				r1[N1++] = i;
			else
				r2[N2++] = i;
		}
	qsort(r1, N1, sizeof(r1[0]), cmp);
	qsort(r2, N2, sizeof(r2[0]), cmp);
	if (dfs(left, right, num) != 2)
		printf("Impossible\n");
	else
	{
		for (i = N - 1; i >= 0; i--)
			printf("%d %d\n", x[s[i]] / 2, w[s[i]]);
	}
}

int main()
{
	int t = 0;
	for (;;)
	{
		scanf("%d%d%d", &L, &W, &N);
		if (!L)
		{
			break;
		}
		init();
		printf("Case %d:\n", ++t);
		solve();
	}
	return 0;
}
