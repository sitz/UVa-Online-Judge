#include <bits/stdc++.h>

using namespace std;

int a[30];
int s[30], ss, n;

int b[30], vis[30], is[30];

int jud()
{
	int i, j, sss = ss, M;
	for (i = 1; i <= n; i++)
	{
		b[i] = a[i];
	}
	while (1)
	{
		M = 0;
		for (i = 1; i <= n; i++)
			if (!vis[i])
			{
				if (M < b[i])
				{
					M = b[i], j = i;
				}
			}
		if (!M)
		{
			return 1;
		}
		b[j] = 0;
		int MM;
		memset(is, 0, sizeof(is));
		while (M--)
		{
			MM = 0;
			for (i = 1; i <= n; i++)
				if (vis[i] && b[i] && !is[i])
				{
					if (MM < b[i])
					{
						MM = b[i], j = i;
					}
				}
			if (!MM)
			{
				return 0;
			}
			b[j]--;
			is[j] = 1;
		}
	}
}
int dfs(int dep, int num, int he, int M1, int M2)
{
	if (M1 > n - num || M2 > num + dep || (he << 1) > ss || ((s[dep] + he) << 1) < ss)
	{
		return 0;
	}
	if (dep == 0)
	{
		return jud();
	}
	vis[dep] = 1;
	if (dfs(dep - 1, num + 1, he + a[dep], M1 > a[dep] ? M1 : a[dep], M2))
	{
		return 1;
	}
	vis[dep] = 0;
	if (dfs(dep - 1, num, he, M1, M2 > a[dep] ? M2 : a[dep]))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int t, ii = 0, i, j, cnt;
	scanf("%d", &t);
	while (t--)
	{
		cnt = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i])
			{
				b[++cnt] = a[i];
			}
		}
		n = cnt;
		for (i = 1; i <= n; i++)
		{
			a[i] = b[i];
		}
		sort(a + 1, a + 1 + n);
		for (i = 1; i <= n; i++)
		{
			s[i] = s[i - 1] + a[i];
		}
		ss = s[n];
		printf("Case %d: ", ++ii);
		if ((ss & 1) || !dfs(n, 0, 0, 0, 0))
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
