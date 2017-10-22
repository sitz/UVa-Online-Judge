#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1 << 30)
#define pii pair<int, int>
#define MP make_pair

int coin[105], dp[10010];

int main()
{
	int t, cas = 1;
	//    scanf("%d", &t);
	while (1)
	{
		int n, x, now, i, j, dd;
		char c;
		scanf("%d%d", &n, &x);
		if (n == 0 && x == 0)
		{
			break;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d%c%d", &now, &c, &dd);
			now = (now * 100) + dd;
			coin[i] = now;
		}
		int cur = coin[x];
		if (cur > 5000)
		{
			double val = 100.00;
			printf("%.2lf\n", val);
		}
		else
		{
			memset(dp, 0, sizeof dp);
			dp[0] = 1;
			for (i = 1; i <= n; i++)
			{
				if (i == x)
				{
					continue;
				}
				for (j = 10000; j >= 0; j--)
				{
					if (dp[j])
					{
						dp[j + coin[i]] = 1;
					}
				}
			}
			int st = (5000 - cur);
			double sol;
			for (i = st + 1; i <= 10000; i++)
			{
				if (dp[i])
				{
					sol = (cur * 100.0) / (i + cur);
					break;
				}
			}
			printf("%.2lf\n", sol);
		}
	}
	return 0;
}
