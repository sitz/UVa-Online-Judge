#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int t, n;
struct Point
{
	double x, y;
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
} p[N];

long long dp[N][N];

bool cmp(Point a, Point b)
{
	return a.x < b.x;
}

double xmul(Point a1, Point a2, Point b1, Point b2)
{
	double ax = a2.x - a1.x, ay = a2.y - a1.y;
	double bx = b2.x - b1.x, by = b2.y - b1.y;
	return ax * by - bx * ay;
}

bool judge(int s, int e, double flag)
{
	for (int i = s + 1; i < e; i++)
	{
		double ans = xmul(p[s], p[i], p[s], p[e]) * flag;
		if (ans <= 0)
		{
			return false;
		}
	}
	return true;
}

long long solve()
{
	memset(dp, 0, sizeof(dp));
	dp[1][0] = dp[0][1] = 1;
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			int k = i - 1;
			dp[i][j] += dp[k][j];
			dp[j][i] += dp[j][k];
		}
		for (int j = 0; j < i - 1; j++)
		{
			if (judge(j, i, 1))
			{
				dp[i][i - 1] += dp[j][i - 1];
			}
			if (judge(j, i, -1))
			{
				dp[i - 1][i] += dp[i - 1][j];
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (judge(i, n - 1, 1))
		{
			ans += dp[i][n - 1];
		}
		if (judge(i, n - 1, -1))
		{
			ans += dp[n - 1][i];
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			p[i].read();
		}
		sort(p, p + n, cmp);
		printf("%lld\n", solve() / 2);
	}
	return 0;
}
