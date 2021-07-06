#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define M 10000

bool range[1000][101];
int cand[1000];

bool constraint_check(int i, int j, int a, int b, int c, int lim)
{
	if (a == 0 && b == 0 && c == 0)
	{
		return true;
	}
	if (b == 0)
	{
		if (a == 0 || c % a != 0 || c / a <= 0 || range[i][c / a] == false)
		{
			return false;
		}
		cand[i] = 1;
		rep(k, lim) range[i][k] = false;
		range[i][c / a] = true;
	}
	else
	{
		REP(k, 1, lim)
		{
			if (range[i][k] == false)
			{
				continue;
			}
			int tmp = c - a * k;
			if (tmp % b != 0 || tmp / b <= 0 || range[j][tmp / b] == false)
			{
				range[i][k] = false, cand[i]--;
			}
		}
	}
	if (a == 0)
	{
		if (b == 0 || c % b != 0 || c / b <= 0 || range[j][c / b] == false)
		{
			return false;
		}
		cand[j] = 1;
		rep(k, lim) range[j][k] = false;
		range[j][c / b] = true;
	}
	else
	{
		REP(k, 1, lim)
		{
			if (range[j][k] == false)
			{
				continue;
			}
			int tmp = c - b * k;
			if (tmp % a != 0 || tmp / a <= 0 || range[i][tmp / a] == false)
			{
				range[j][k] = false, cand[j]--;
			}
		}
	}
	if (cand[i] == 0 || cand[j] == 0)
	{
		return false;
	}
	return true;
}

bool solve(int n, int m, int k, int *a, int *indexi, int *b, int *indexj, int *c)
{
	rep(i, n)
	{
		rep(j, k + 1) range[i][j] = true;
		range[i][0] = false;
		cand[i] = k;
	}
	rep(i, m)
	{
		if (constraint_check(indexi[i], indexj[i], a[i], b[i], c[i], k + 1) == false)
		{
			return false;
		}
	}
	return true;
}

main()
{
	int te;
	int a[M], b[M], c[M], indexi[M], indexj[M];
	cin >> te;
	while (te--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		rep(i, m)
		{
			cin >> a[i] >> indexi[i] >> b[i] >> indexj[i] >> c[i];
			indexi[i]--;
			indexj[i]--;
		}
		if (solve(n, m, k, a, indexi, b, indexj, c))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
}
