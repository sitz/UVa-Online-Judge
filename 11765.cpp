#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXE = 500000;
const int INF = 2100000000;

int dis[MAXN], pre[MAXN], gap[MAXN], arc[MAXN], f[MAXE], cap[MAXE], fst[MAXN], nxt[MAXE], vv[MAXE], q[MAXN], vis[MAXN], X[MAXN], Y[MAXN];

int sap(int s, int t, int n)
{
	int j, mindis, ans = 0, front = 0, rear = 1, u, v, low;
	bool found;

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
			continue;

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

int main()
{
	int T, n, m, u, v, i, j, k, e;
	int ii = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n,&m);
		memset(fst, 0, sizeof(fst));
		e = 2;
		int st = n + 1, ed = st + 1;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &X[i]);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &Y[i]);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &j);
			if (j == 0)
			{
				add(st, i, X[i], e), add(i, ed, Y[i], e);
			}
			else if (j > 0)
			{
				add(st, i, X[i], e), add(i, ed, 2100000000, e);
			}
			else
			{
				add(st, i, 2100000000, e), add(i, ed, Y[i], e);
			}
		}
		while (m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			add(i, j, k, e);
			add(j, i, k, e);
		}
		printf("%d\n", sap(st, ed, ed));
	}
	return 0;
}
