#include <bits/stdc++.h>

using namespace std;

const int maxn = 50010;
const int maxe = 210000;

int first[maxn], nxt[maxe], vv[maxe], w[maxe];
int dis[maxn], dis1[maxn], dif[maxn];
int d[maxn];
vector<int> V[maxn];
vector<int> B[maxn];
vector<int> W[maxn];

queue<int> q;

void bfs(int n)
{
	while (!q.empty())
	{
		q.pop();
	}
	int u, v, e;
	q.push(n);
	memset(dis1, -1, sizeof(dis1));
	dis1[n] = 0;
	memset(dif, 0, sizeof(dif));
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		e = first[u];
		while (e)
		{
			v = vv[e];
			if (dis1[v] < 0)
			{
				dis1[v] = dis1[u] + w[e];
			}
			else if (dis1[v] > dis1[u] + w[e])
			{
				dif[v] = 1;
			}
			else if (dis1[v] < dis1[u] + w[e])
			{
				dis1[v] = dis1[u] + w[e], dif[v] = 1;
			}
			if (dif[u])
			{
				dif[v] = 1;
			}
			d[v]--;
			if (!d[v])
			{
				q.push(v);
			}
			e = nxt[e];
		}
	}
}
void add1(int u, int v, int ww, int &e)
{
	nxt[e] = first[u], vv[e] = v, w[e] = ww, first[u] = e++;
	d[v]++;
}
void add2(int u, int v, int ww, int &e, int b)
{
	add1(u, v, ww, e);
	V[v].push_back(u);
	W[v].push_back(ww);
	B[v].push_back(b);
}
int is[maxn], gai[maxn];
int spfa(int n)
{
	memset(dis, -1, sizeof(dis));
	memset(is, 0, sizeof(is));
	memset(gai, 0, sizeof(gai));
	dis[1] = 0;
	while (!q.empty())
	{
		q.pop();
	}
	q.push(1);
	int u, v, e, i;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		e = first[u];
		int tmp = 0;
		for (i = 0; i < V[u].size(); i++)
		{
			v = V[u][i];
			if (dis[v] + W[u][i] < dis[u])
			{
				if (dif[u])
				{
					return 0;
				}
				tmp = 1;
			}
		}
		if (tmp)
		{
			for (i = 0; i < V[u].size(); i++)
			{
				v = V[u][i];
				gai[B[u][i]] = dis1[1] - dis1[u] - dis[v] - W[u][i];
			}
			dis[u] = dis1[1] - dis1[u];
		}
		e = first[u];
		while (e)
		{
			v = vv[e];
			if (dis[v] < dis[u] + w[e])
			{
				dis[v] = dis[u] + w[e];
			}
			--d[v];
			if (!d[v])
			{
				q.push(v);
			}
			e = nxt[e];
		}
	}
	return 1;
}
int nu[maxn], nv[maxn], nw[maxn];
int main()
{
	int n, m, i, j, u, v, e;
	int ca = 0;
	while (scanf("%d%d", &n, &m), n || m)
	{
		memset(first, 0, sizeof(first));
		memset(d, 0, sizeof(d));
		e = 2;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &u, &v, &j);
			add1(v, u, j, e);
			nu[i] = u, nv[i] = v, nw[i] = j;
		}
		bfs(n);
		memset(first, 0, sizeof(first));
		memset(d, 0, sizeof(d));
		e = 2;
		for (i = 1; i <= n; i++)
		{
			V[i].clear(), B[i].clear(), W[i].clear();
		}
		for (i = 1; i <= m; i++)
		{
			u = nu[i], v = nv[i], j = nw[i];
			add2(u, v, j, e, i);
		}
		printf("Case %d: ", ++ca);
		if (!spfa(n))
		{
			puts("No solution");
		}
		else
		{
			j = 0;
			for (i = 1; i <= m; i++)
				if (gai[i])
				{
					j++;
				}
			printf("%d %d\n", j, dis1[1]);
			for (i = 1; i <= m; i++)
				if (gai[i])
				{
					printf("%d %d\n", i, gai[i]);
				}
		}
	}
	return 0;
}
