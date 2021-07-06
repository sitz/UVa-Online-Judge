#include <bits/stdc++.h>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n;

vector<int> adj[N];
int root = 0;
int a[N], b[N], c[N];
int x[N], y[N];

bool cmp_vec(const pair<int, int> &u, const pair<int, int> &v)
{
	return u.first - u.second < v.first - v.second;
}

void dfs(int cur, int fa)
{
	vector<pair<int, int>> vec;
	for (int i = 0; i < (int)adj[cur].size(); ++i)
	{
		int v = adj[cur][i];
		if (v == fa)
			continue;
		dfs(v, cur);
		vec.push_back(make_pair(x[v], y[v]));
	}
	sort(vec.begin(), vec.end(), cmp_vec);

	y[cur] = b[cur] + c[cur];
	x[cur] = 0;
	for (int i = 0; i < (int)vec.size(); ++i)
	{
		x[cur] = max(vec[i].first, x[cur] + vec[i].second);
		y[cur] += vec[i].second;
	}
	x[cur] = max(a[cur], x[cur] + b[cur] + c[cur]);
}

int Ans()
{
	dfs(root, -1);
	return x[root];
}

int main()
{
	int tcas = 0;
	while (cin >> n, n)
	{
		for (int i = 1; i <= n; ++i)
			scanf("%d%d%d", a + i, b + i, c + i), adj[i].clear();
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans = INF;
		for (int i = 1; i <= n; ++i)
		{
			root = i;
			ans = min(ans, Ans());
		}
		printf("Case %d: %d\n", ++tcas, ans);
	}
}
