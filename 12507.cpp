#include <bits/stdc++.h>

using namespace std;

int u[110], v[110], w[110], g[20], vis[20];
int r[110], p[20];
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
bool cmp(int i, int j)
{
	return w[i] < w[j];
}
inline int Kruskal(int n, int m, int h)
{
	for (int i = 0; i < m; i++)
	{
		r[i] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
	sort(r, r + m, cmp);
	int ans = 0;
	int d = 1;
	for (int i = 0; i < m; i++)
	{
		int e = r[i];
		if (vis[u[e]] && vis[v[e]])
		{
			int x = find(u[e]);
			int y = find(v[e]);
			if (x != y)
			{
				ans += w[e];
				p[x] = y;
				d++;
			}
		}
	}
	if (d < h)
	{
		ans = 1000000;
	}
	return ans;
}
int main()
{
	int t, m, n, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &g[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
		}
		int maxx = g[1];
		for (int i = 1; i < (1 << n); i++)
		{
			if (i % 2 == 1)
			{
				memset(vis, 0, sizeof(vis));
				int x = 0, h = 0;
				;
				for (int j = 0; j < n; j++)
				{
					if (i & (1 << j))
					{
						vis[j + 1] = 1;
						x += g[j + 1];
						h++;
					}
				}
				if (x > maxx)
				{
					//printf("%d*****%d\n",i,x);
					int c = Kruskal(n, m, h);
					// printf("%d\n",c);
					if (c <= k)
					{
						maxx = x;
					}
				}
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}
