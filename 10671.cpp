#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for (int(i) = 1; (i) <= (n); (i)++)
const int maxn = 11;
int n, x, r[maxn], c[maxn], sx, sy, ex, ey, t1, t2;
const double eps = 1e-9;
const int mod = 2520;
const int maxt = 2520 * 21;
double d[maxn][maxn][maxt], cost[maxn][maxn][maxt];
bool vis[maxn][maxn][maxt];
double fee(int i)
{
	return x * 1.0 / (80 - 0.03 * (i * 5) * (i * 5));
}
struct node
{
	int x, y, z;
	node(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
} pa[maxn][maxn][maxt];
double dp2(int i, int j, int k)
{
	if (vis[i][j][k])
	{
		return d[i][j][k];
	}
	vis[i][j][k] = 1;
	double &ans = d[i][j][k];
	if (i == ex && j == ey)
	{
		double tem = 12.0 * x * k / mod;
		cost[i][j][k] = 0;
		if (tem >= t1 && tem <= t2)
		{
			ans = tem;
		}
		else
		{
			ans = 1e6;
		}
		return ans;
	}
	ans = 1e6;
	if (i != ex)
	{
		int ad = (ex > i ? 1 : -1);
		for (int v = 1; v <= r[j]; v++)
		{
			double tem = dp2(i + ad, j, mod / v + k);
			if (tem < ans)
			{
				ans = tem;
				cost[i][j][k] = cost[i + ad][j][mod / v + k] + fee(v);
			}
			else if (tem == ans)
			{
				cost[i][j][k] = min(cost[i][j][k], cost[i + ad][j][mod / v + k] + fee(v));
			}
		}
	}
	if (j != ey)
	{
		int ad = (ey > j ? 1 : -1);
		for (int v = 1; v <= c[i]; v++)
		{
			double tem = dp2(i, j + ad, mod / v + k);
			if (tem < ans)
			{
				ans = tem;
				cost[i][j][k] = cost[i][j + ad][mod / v + k] + fee(v);
			}
			else if (tem == ans)
			{
				cost[i][j][k] = min(cost[i][j][k], cost[i][j + ad][mod / v + k] + fee(v));
			}
		}
	}
	return ans;
}
double dp(int i, int j, int k)
{
	if (vis[i][j][k])
	{
		return d[i][j][k];
	}
	vis[i][j][k] = 1;
	double &ans = d[i][j][k];
	if (i == ex && j == ey)
	{
		double tem = 12.0 * x * k / mod;
		if (tem >= t1 && tem <= t2)
		{
			cost[i][j][k] = tem;
			d[i][j][k] = 0;
		}
		else
		{
			ans = 1e6;
		}
		return ans;
	}
	ans = 1e6;
	if (i != ex)
	{
		int ad = (ex > i ? 1 : -1);
		for (int v = 1; v <= r[j]; v++)
		{
			double tem = dp(i + ad, j, mod / v + k) + fee(v);
			if (tem < ans)
			{
				ans = tem;
				cost[i][j][k] = cost[i + ad][j][mod / v + k];
			}
			else if (tem == ans)
			{
				cost[i][j][k] = min(cost[i][j][k], cost[i + ad][j][mod / v + k]);
			}
		}
	}
	if (j != ey)
	{
		int ad = (ey > j ? 1 : -1);
		for (int v = 1; v <= c[i]; v++)
		{
			double tem = dp(i, j + ad, mod / v + k) + fee(v);
			if (tem < ans)
			{
				ans = tem;
				cost[i][j][k] = cost[i][j + ad][mod / v + k];
			}
			else if (tem == ans)
			{
				cost[i][j][k] = min(cost[i][j][k], cost[i][j + ad][mod / v + k]);
			}
		}
	}
	return ans;
}
void print_ans(int i, int j, int k)
{
	if (i == ex && j == ey)
	{
		return;
	}
	node &te = pa[i][j][k];
	printf("%d %d %d --> v : %d  limit : %d\n", i, j, k, mod / (te.z - k), (te.x == i ? r[i] : c[j]));
	print_ans(te.x, te.y, te.z);
}
void init()
{
	int x1 = min(sx, ex), x2 = max(sx, ex);
	int y1 = min(sy, ey), y2 = max(sy, ey);
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			for (int k = 0; k < maxt; k++)
			{
				vis[i][j][k] = false;
			}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		scanf("%d %d", &n, &x);
		rep1(i, n)
		{
			scanf("%d", &r[i]);
			r[i] /= 5;
		}
		rep1(i, n)
		{
			scanf("%d", &c[i]);
			c[i] /= 5;
		}
		scanf("%d %d %d %d %d %d", &sx, &sy, &ex, &ey, &t1, &t2);
		printf("Scenario %d:\n", kase);
		int flag = 1;
		init();
		dp2(sx, sy, 0);
		if (d[sx][sy][0] == 1e6)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("The earliest  arrival: %.0lf minutes, fuel %.2lf gallons\n", ceil(d[sx][sy][0]), cost[sx][sy][0]);
		init();
		dp(sx, sy, 0);
		printf("The economical travel: %.0lf minutes, fuel %.2lf gallons\n", ceil(cost[sx][sy][0]), d[sx][sy][0]);
	}
	return 0;
}
