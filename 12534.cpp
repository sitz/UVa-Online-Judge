#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600;
const int MAXE = 80000;
const int INF = 2100000000;

int dis[MAXN], pre[MAXN], gap[MAXN], arc[MAXN], f[MAXE], cap[MAXE], fst[MAXN], nxt[MAXE], vv[MAXE];

int sap(int s, int t, int n)
{
	int q[MAXN], j, mindis, ans = 0, front = 0, rear = 1, u, v, low;
	bool found, vis[MAXN];
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memset(vis, 0, sizeof(vis));
	memset(arc, 0, sizeof(arc));
	memset(f, 0, sizeof(f));
	u = s;
	low = INF;
	pre[s] = s;
	while (dis[s] < n)
	{
		found = false;
		for (int &e = arc[u]; e; e = nxt[e])
			if (dis[vv[e]] == dis[u] - 1 && cap[e] > f[e])
			{
				found = true;
				v = vv[e];
				low = low < cap[e] - f[e] ? low : cap[e] - f[e];
				pre[v] = u;
				u = v;
				if (u == t)
				{
					while (u - s)
					{
						u = pre[u];
						f[arc[u]] += low;
						f[arc[u] ^ 1] -= low;
					}
					ans += low;
					low = INF;
				}
				break;
			}
		if (found)
		{
			continue;
		}
		mindis = n;
		for (int e = fst[u]; e; e = nxt[e])
		{
			if (mindis > dis[vv[e]] && cap[e] > f[e])
			{
				mindis = dis[vv[j = e]];
				arc[u] = e;
			}
		}
		gap[dis[u]]--;
		if (gap[dis[u]] == 0)
		{
			return ans;
		}
		dis[u] = mindis + 1;
		gap[dis[u]]++;
		u = pre[u];
	}
	return ans;
}

inline void add(int u, int v, int c, int &e)
{
	nxt[e] = fst[u], vv[e] = v, cap[e] = c, fst[u] = e++;
	nxt[e] = fst[v], vv[e] = u, cap[e] = 0, fst[v] = e++;
}
char str[100][100];
int sc[100], sr[100];

int solve(int n, int m, int x, int y)
{
	int s = n + m + 1, t = s + 1;
	int e = 2, i, j, ans = 0, ss = 0;
	memset(fst, 0, sizeof(fst));
	for (i = 1; i <= n; i++)
	{
		add(s, i, abs(sr[i] - x), e), ans += abs(sr[i] - x), ss += abs(sr[i] - x);
	}
	for (i = 1; i <= m; i++)
	{
		add(i + n, t, abs(sc[i] - y), e), ans += abs(sc[i] - y);
	}
	for (i = 1; i <= n; i++)
		if (sr[i] > x)
			for (j = 1; j <= m; j++)
				if (sc[j] > y && str[i - 1][j - 1] == '1')
				{
					add(i, j + n, 1, e);
				}
	for (i = 1; i <= n; i++)
		if (sr[i] < x)
			for (j = 1; j <= m; j++)
				if (sc[j] < y && str[i - 1][j - 1] == '0')
				{
					add(i, j + n, 1, e);
				}
	i = sap(s, t, t);
	return ans - i + min(ss - i, ans - ss - i);
}

int main()
{
	int t, n, m, i, j, k;
	int ii = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		memset(sc, 0, sizeof(sc));
		memset(sr, 0, sizeof(sr));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (str[i - 1][j - 1] == '1')
				{
					sr[i]++, sc[j]++;
				}
		int ans = 210000;
		for (i = 0; i <= m; i++)
			if (i * n % m == 0)
			{
				j = solve(n, m, i, i * n / m);
				ans = min(ans, j);
			}
		printf("Case %d: %d\n", ++ii, ans);
	}
	return 0;
}
