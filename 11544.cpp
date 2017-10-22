#include <bits/stdc++.h>

using namespace std;

const int MXN = 107;

const long long INF = 1LL << 60;

long long dist[MXN];
int c[MXN][MXN];
int num[MXN], e[MXN][MXN];
long long w[MXN][MXN];
int cap[MXN];
bool del[MXN];
bool vis[MXN];
int pre[MXN];

int n, m;
int N, s, t;
bool ok[MXN];

int maxFlow()
{
	int ret = 0;
	while (true)
	{
		queue<int> q;
		for (int i = 0; i < N; ++i)
		{
			dist[i] = -INF;
			vis[i] = false;
			pre[i] = -1;
		}
		q.push(s);
		vis[s] = true;
		dist[s] = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = false;
			for (int i = 0; i < N; ++i)
				if (c[u][i] > 0)
				{
					if (del[i])
					{
						continue;
					}
					if (dist[i] < dist[u] + w[u][i])
					{
						dist[i] = dist[u] + w[u][i];
						pre[i] = u;
						if (!vis[i])
						{
							vis[i] = true;
							q.push(i);
						}
					}
				}
		}
		if (dist[t] == -INF)
		{
			break;
		}
		int minFlow = (int)1e5;
		for (int u = t; u != s; u = pre[u])
		{
			minFlow = min(minFlow, c[pre[u]][u]);
		}
		ret += minFlow;
		for (int u = t; u != s; u = pre[u])
		{
			c[pre[u]][u] -= minFlow;
			c[u][pre[u]] += minFlow;
		}
	}
	return ret;
}

void build()
{
	N = n + m + 2;
	s = 0;
	t = n + m + 1;
	memset(c, 0, sizeof c);
	memset(w, 0, sizeof w);
	for (int i = 1; i <= m; ++i)
	{
		c[n + i][t] = cap[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		c[s][i] = 1;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= num[i]; ++j)
		{
			c[i][n + e[i][j]] = 1;
		}
}

void printG()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (c[i][j] > 0)
			{
				cerr << i << ' ' << j << ' ' << c[i][j] << ' ' << w[i][j] << endl;
			}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int numCase = 1; numCase <= T; ++numCase)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d", cap + i);
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", num + i);
			for (int j = 1; j <= num[i]; ++j)
			{
				scanf("%d", e[i] + j);
			}
		}
		build();
		for (int i = 1; i <= n; ++i)
		{
			w[s][i] = 1LL << (n - i);
			w[i][s] = -w[s][i];
		}
		memset(ok, 0, sizeof ok);
		memset(del, 0, sizeof del);
		int ans = maxFlow();
		for (int i = 1; i <= n; ++i)
			if (c[s][i] == 0)
			{
				ok[i] = true;
			}
		printf("Case #%d:\n%d applicant(s) can be hired.\n", numCase, ans);
		for (int i = 1; i <= n; ++i)
			if (ok[i])
			{
				build();
				for (int j = 1; j <= num[i]; ++j)
				{
					int v = n + e[i][j];
					w[i][v] = 1LL << (m - j);
					w[v][i] = -w[i][v];
				}
				maxFlow();
				del[i] = true;
				for (int j = 1; j <= num[i]; ++j)
					if (c[i][n + e[i][j]] == 0)
					{
						printf("%d %d\n", i, e[i][j]);
						--cap[e[i][j]];
					}
			}
	}
	return 0;
}
