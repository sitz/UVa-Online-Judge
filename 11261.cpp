#include <bits/stdc++.h>

using namespace std;

#define MAXN 80010
bool vis1[MAXN * 2 + 10], vis2[MAXN * 2 + 10];
int main()
{
	//	freopen("1.in","r",stdin);
	int T, n, m, i, x, y, t = 0;
	scanf("%d", &T);
	while (true)
	{
		if (t == T)
		{
			break;
		}
		t++;
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		scanf("%d%d", &n, &m);
		long long ans = 0;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			if (!vis1[x + y - 1])
			{
				if (x + y - 1 > n)
				{
					ans += 2 * n - (x + y - 1);
				}
				else
				{
					ans += x + y - 1;
				}
			}
			vis1[x + y - 1] = 1;
			if (!vis2[x - y + n])
			{
				if (x - y + n > n)
				{
					ans += n - (x - y);
				}
				else
				{
					ans += x - y + n;
				}
			}
			vis2[x - y + n] = 1;
		}
		long long cnt1 = 0, cnt2 = 0;
		for (i = 1; i <= n; i++)
		{
			x = i;
			if (i % 2 == 1)
			{
				if (vis2[n - x + 1])
				{
					cnt1++;
				}
				if (vis2[n + x - 1] && (n + x - 1) != n)
				{
					cnt1++;
				}
				if (vis1[i])
				{
					ans -= cnt1;
				}
			}
			else if (i % 2 == 0)
			{
				if (vis2[n - x + 1])
				{
					cnt2++;
				}
				if (vis2[n + x - 1] && (n + x - 1) != n)
				{
					cnt2++;
				}
				if (vis1[i])
				{
					ans -= cnt2;
				}
			}
		}
		cnt1 = 0, cnt2 = 0;
		for (i = 2 * n - 1; i > n; i--)
		{
			x = 2 * n - i;
			if (i % 2 == 1)
			{
				if (vis2[n - x + 1])
				{
					cnt1++;
				}
				if (vis2[n + x - 1] && (n + x - 1) != n)
				{
					cnt1++;
				}
				if (vis1[i])
				{
					ans -= cnt1;
				}
			}
			else if (i % 2 == 0)
			{
				if (vis2[n - x + 1])
				{
					cnt2++;
				}
				if (vis2[n + x - 1] && (n + x - 1) != n)
				{
					cnt2++;
				}
				if (vis1[i])
				{
					ans -= cnt2;
				}
			}
		}
		ans = n * n - ans;
		printf("Case #%d: ", t);
		printf("%lld\n", ans);
		//      if(t!=T) printf("\n");
	}
}
