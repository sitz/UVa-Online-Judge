#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
struct Edge
{
	int u;
	int v;
	int w;
} edge[maxn];
int f[maxn];
int n, m;
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		int u, v, w;
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v >> w;
			edge[i].u = u;
			edge[i].v = v;
			edge[i].w = w;
		}
		int flag = 0;
		int ans = 10000000;
		int Max = 0, Min = 10000000;
		sort(edge + 1, edge + 1 + m, cmp);
		for (int i = 1; i <= m; i++)
		{
			Max = 0;
			Min = 10000000;
			int k = 0;
			for (int j = 0; j <= n; j++)
			{
				f[j] = j;
			}
			for (int j = i; j <= m; j++)
			{
				int x = find(edge[j].u);
				int y = find(edge[j].v);
				if (x != y)
				{
					k++;
					f[x] = y;
					if (edge[j].w > Max)
					{
						Max = edge[j].w;
					}
					if (edge[j].w < Min)
					{
						Min = edge[j].w;
					}
				}
			}
			if (k == n - 1 && Max - Min < ans)
			{
				ans = Max - Min;
				flag = 1;
			}
		}
		if (flag)
		{
			cout << ans << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
