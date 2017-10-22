#include <bits/stdc++.h>

using namespace std;

#define MX 100005
#define REP(i, n) for (int i = 0; i < (n); i++)
#define OREP(i, n) for (int i = 1; i <= (n); i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;

int n, m, k, t;

double dp[MX];
void init()
{
	dp[0] = 1.0 * k / (n - 1);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] * (k - i) / (n - 1 - i);
	}
}
int main()
{
	int c = 1;
	while (scanf("%d %d", &n, &m) && n)
	{
		k = n - 1 - min(n - 1, m * 2);
		init();
		double ret = 0.0;
		for (int i = 0; i < n; i++)
		{
			t = min(i, m) + min(m, n - i - 1);
			double p = dp[t - 1];
			if (t == 0)
			{
				p = 1;
			}
			ret += 1 - p;
		}
		printf("Case %d: %.4lf\n", c++, ret);
	}
	return 0;
}
