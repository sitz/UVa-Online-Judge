#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 5, MAXK = 30 + 5, INF = 1 << 30;
int T = 0, n, k, d[MAXN], dis_sum[MAXN][MAXN], pos[MAXN][MAXN];
struct DP
{
	int v, s, t, depot;
} dp[MAXN][MAXN];

int Dis_Sum(int x, int y)
{
	int &res = dis_sum[x][y];
	if (res >= 0)
		return res;
	res = INF;
	for (int i = x; i <= y; i++)
	{
		int tmp = 0;
		for (int j = x; j <= y; j++)
			tmp += (int)abs((double)(d[j] - d[i]));
		if (tmp < res)
			res = tmp, pos[x][y] = i;
	}
	return res;
}
void print_ans(int x, int y)
{
	if (!x)
		return;
	DP &d = dp[x][y];
	int count = 0;
	for (int i = d.s; i <= d.t; i++)
		count++;
	print_ans(x - 1, y - count);
	if (count > 1)
		printf("Depot %d at restaurant %d serves restaurants %d to %d\n", x, d.depot, d.s, d.t);
	else
		printf("Depot %d at restaurant %d serves restaurant %d\n", x, d.depot, d.s);
}

int main()
{
	while (scanf("%d%d", &n, &k))
	{
		if (!n && !k)
			break;
		T++;
		for (int i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		memset(dp, 0, sizeof(dp));
		memset(dis_sum, -1, sizeof(dis_sum));
		for (int i = 1; i <= n; i++)
			dp[0][i].v = INF;
		for (int i = 1; i <= k; i++)
			for (int j = i; j <= n; j++)
			{
				dp[i][j].v = INF;
				for (int k = j; k >= 1; k--)
					if (dp[i - 1][k - 1].v + Dis_Sum(k, j) < dp[i][j].v)
					{
						dp[i][j].v = dp[i - 1][k - 1].v + Dis_Sum(k, j);
						dp[i][j].depot = pos[k][j];
						dp[i][j].s = k;
						dp[i][j].t = j;
					}
			}
		printf("Chain %d\n", T);
		print_ans(k, n);
		printf("Total distance sum = %d\n", dp[k][n].v);
		printf("\n");
	}
	return 0;
}
