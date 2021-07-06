#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL LIM = 1000000000000000LL;
const LL INF = LIM + 10LL;
const LL pr[] = {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL, 19LL, 23LL, 29LL, 31LL, 37LL, 41LL, 43LL, 47LL, 53LL, 59LL};

LL dp[5005 + 2][18];

LL go(int p, LL nd)
{
	if (nd == 1LL)
	{
		return 1LL;
	}
	if (p == 16)
	{
		return INF;
	}
	LL &ret = dp[nd][p];
	if (ret != -1LL)
	{
		return ret;
	}
	ret = INF;
	LL nm = 1LL;
	for (int i = 1; i <= 63; i++)
	{
		if (nm > (INF / pr[p]))
		{
			break;
		}
		nm *= pr[p];
		if (nd % (i + 1) == 0)
		{
			LL tmp = go(p + 1, nd / (i + 1));
			if (nm < INF / tmp)
			{
				ret = min(ret, nm * tmp);
			}
		}
	}
	return ret;
}

int main()
{
	int t = 1, n;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(dp, -1, sizeof(dp));
		LL ans = go(0, (LL)n);
		printf("Case %d: ", t++);
		if (ans > LIM)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
