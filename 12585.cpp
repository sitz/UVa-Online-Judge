#include <bits/stdc++.h>

using namespace std;

static double f[333][333], g[333][333];

void solve(int n, int m, int step)
{
	if ((n == m) || (step > 100))
	{
		f[n][m] = 0.5;
		g[n][m] = 1.0;
		return;
	}
	if (n > m)
	{
		solve(n - m, m * 2, step + 1);
		f[n][m] = 0.5 + 0.5 * f[n - m][m * 2];
		g[n][m] = 0.5 + 0.5 * (1 + g[n - m][m * 2]);
	}
	else
	{
		solve(n * 2, m - n, step + 1);
		f[n][m] = 0.5 * f[n * 2][m - n];
		g[n][m] = 0.5 + 0.5 * (1 + g[n * 2][m - n]);
	}
}

int main()
{
	int n, m, T;
	scanf("%d", &T);
	for (int caseT = 1; caseT <= T; caseT++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= 300; i++)
			for (int j = 0; j <= 300; j++)
			{
				f[i][j] = -1.0;
			}
		memset(g, 0, sizeof(g));
		solve(n, m, 0);
		printf("Case %d: %.6f %.6f\n", caseT, g[n][m], f[n][m]);
	}
	return 0;
}
