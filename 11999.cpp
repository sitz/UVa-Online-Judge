#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

bool visit[MAXN][MAXN];
int n, m, a[MAXN][MAXN], tmp[MAXN * MAXN], tmptmp[MAXN * MAXN], mv[MAXN][MAXN][2], cirId[MAXN][MAXN], totcir, cirDis[MAXN][MAXN], cirLen[MAXN * MAXN], cirMove[MAXN * MAXN];

long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
	if (b)
	{
		long long ret = ex_gcd(b, a % b, x, y), tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return ret;
	}
	else
	{
		x = 1;
		y = 0;
		return a;
	}
}

long long mod[MAXN * MAXN], ans[MAXN * MAXN];

bool solve(long long &m0, long long &a0, int m, int a)
{
	long long y, x;
	long long g = ex_gcd(m0, m, x, y);
	if (abs(a - a0) % g)
	{
		return 0;
	}
	x *= (a - a0) / g;
	x %= m / g;
	a0 = (x * m0 + a0);
	m0 *= m / g;
	a0 %= m0;
	if (a0 < 0)
	{
		a0 += m0;
	}
	return 1;
}

long long MLES()
{
	bool flag = 1;
	long long m0 = 1, a0 = 0;
	for (int i = 0; i < totcir; i++)
		if (!solve(m0, a0, mod[i], ans[i]))
		{
			flag = 0;
			break;
		}
	if (flag)
	{
		return a0;
	}
	return -1;
}

int main()
{
	int totCas;
	scanf("%d", &totCas);
	for (int cas = 1; cas <= totCas; cas++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = i * m + j;
			}
		}

		int cur = 0, dir = 0;
		for (int i = 0; i < n + m; i++)
		{
			if (i == n)
			{
				continue;
			}
			int sx, sy;
			if (i < n)
			{
				sx = i;
				sy = 0;
			}
			else
			{
				sx = n - 1;
				sy = i - n;
			}
			int tmpcur = 0;
			while (true)
			{
				tmptmp[tmpcur++] = a[sx][sy];
				if (sx == 0 || sy == m - 1)
				{
					break;
				}
				sx--;
				sy++;
			}
			dir = 1 - dir;
			if (dir == 1)
			{
				for (int j = 0; j < tmpcur; j++)
				{
					tmp[cur++] = tmptmp[j];
				}
			}
			else
			{
				for (int j = tmpcur - 1; j >= 0; j--)
				{
					tmp[cur++] = tmptmp[j];
				}
			}
		}
		for (int i = 0; i < cur; i++)
		{
			mv[tmp[i] / m][tmp[i] % m][0] = i / m;
			mv[tmp[i] / m][tmp[i] % m][1] = i % m;
		}
		totcir = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (visit[i][j] == false)
				{
					int curX = i, curY = j;
					cirLen[totcir] = 0;
					while (true)
					{
						visit[curX][curY] = true;
						cirId[curX][curY] = totcir;
						cirDis[curX][curY] = cirLen[totcir]++;
						int nxtX = mv[curX][curY][0];
						int nxtY = mv[curX][curY][1];
						curX = nxtX;
						curY = nxtY;
						if (visit[curX][curY])
						{
							break;
						}
					}
					totcir++;
				}
		memset(cirMove, -1, sizeof(cirMove));
		bool flag = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int val;
				scanf("%d", &val);
				val--;
				int preX = val / m;
				int preY = val % m;
				if (cirId[preX][preY] != cirId[i][j])
				{
					flag = false;
				}
				int dis = cirDis[i][j] - cirDis[preX][preY];
				dis = -dis;
				if (dis < 0)
				{
					dis += cirLen[cirId[i][j]];
				}
				if (cirMove[cirId[i][j]] == -1)
				{
					cirMove[cirId[i][j]] = dis;
				}
				if (cirMove[cirId[i][j]] != dis)
				{
					flag = false;
				}
			}
		if (!flag)
		{
			puts("-1");
			continue;
		}
		for (int i = 0; i < totcir; i++)
		{
			mod[i] = cirLen[i];
			ans[i] = cirMove[i];
		}
		printf("%lld\n", MLES());
	}
	return 0;
}
