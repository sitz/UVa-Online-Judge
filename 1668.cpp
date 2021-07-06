#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int ret = 0;
vector<pair<int, int> > g[MAXN];

void dfs(int u, int p, int pw)
{
	int mx = pw, sum = pw;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i].first;
		if (v == p)
		{
			continue;
		}
		dfs(v, u, g[u][i].second);
		mx = max(mx, g[u][i].second);
		sum += g[u][i].second;
	}
	if (mx * 2 >= sum)
	{
		// exactly gen #mx-pw path, connected or not
		ret += mx - pw;
	}
	else
	{
		// pair branch connect(completed path), reserve #pw to parent
		ret += (sum + 1) / 2 - pw;
	}
}

int main()
{
	int T, t = 0, N, x, y, v;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i <= N; i++)
		{
			g[i].clear();
		}
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d%d", &x, &y, &v);
			g[x].push_back(make_pair(y, v));
			g[y].push_back(make_pair(x, v));
		}
		ret = 0;
		dfs(1, -1, 0);
		printf("Case #%d: %d\n", ++t, ret);
	}
	return 0;
}
