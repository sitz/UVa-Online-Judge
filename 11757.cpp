#include <bits/stdc++.h>

using namespace std;

#define maxn 210
#define maxe 50010
#define INF 1 << 30
#define LL long long
#define eps 1e-15
#define PI acos(-1.0)
int n, m;
int f[maxe], cap[maxe];//flow[maxn][maxn];
int first[maxn], dis[maxn], gap[maxn], arc[maxn], Next[maxe], vv[maxe], pre[maxn], add, tot;
void adj(int u, int v, int ca)
{
	Next[add] = first[u];
	vv[add] = v;
	cap[add] = ca;
	first[u] = add++;
	Next[add] = first[v];
	vv[add] = u;
	cap[add] = 0;
	first[v] = add++;
}
int sap(int s, int t, int n)
{
	int q[maxn], i, j, mindis, front = 0, rear = 1, u, v, e;
	int ans = 0, low;
	bool found, vis[maxn];
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memset(vis, 0, sizeof(vis));
	memset(arc, 0, sizeof(arc));
	q[0] = t;
	vis[t] = true;
	dis[t] = 0;
	gap[0] = 1;
	while (front < rear)
	{
		u = q[front++];
		e = first[u];
		while (e)
		{
			v = vv[e];
			if (!vis[v])
			{
				dis[v] = dis[u] + 1;
				vis[v] = true;
				q[rear++] = v;
				gap[dis[v]]++;
				arc[v] = first[v];
			}
			e = Next[e];
		}
	}
	u = s;
	low = INF;
	pre[s] = s;//gap[s]=n;
	while (dis[s] < n)
	{
		found = false;
		for (int &e = arc[u]; e; e = Next[e])
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
		for (int e = first[u]; e; e = Next[e])
			if (mindis > dis[vv[e]] && cap[e] > f[e])
			{
				mindis = dis[vv[j = e]];
				arc[u] = e;
			};
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
struct node
{
	int x, y;
} pt[maxn];
int L, W;
inline int sqr(int a)
{
	return a * a;
}
int cal(int a, int b)
{
	return sqr(pt[a].x - pt[b].x) + sqr(pt[a].y - pt[b].y);
}
int main()
{
	int ncase, tt = 0, i, j, u, v, s, e;
	while (scanf("%d %d %d %d", &L, &W, &n, &m), L || W || n || m)
	{
		memset(first, 0, sizeof(first));
		memset(f, 0, sizeof(f));
		add = 2;
		s = 0, e = n * 2 + 1;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d %d", &pt[i].x, &pt[i].y);
		}
		for (i = 1; i <= n; i++)
		{
			if (pt[i].y <= m)
			{
				adj(s, i, 1);
			}
			if (pt[i].y + m >= W)
			{
				adj(i + n, e, 1);
			}
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (i != j)
				{
					if (cal(i, j) <= 4 * m * m)
					{
						adj(i + n, j, 1);
					}
				}
		for (i = 1; i <= n; ++i)
		{
			adj(i, i + n, 1);
		}
		printf("Case %d: %d\n", ++tt, sap(s, e, n * 2 + 2));
	}
	return 0;
}
