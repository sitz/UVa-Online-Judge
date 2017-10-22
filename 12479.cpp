#include <bits/stdc++.h>

using namespace std;

#define MAXN 30009
#define MAXE 60009

int fo[MAXE], to[MAXE], ne[MAXE], fin[MAXE], used[MAXN], col[MAXN], lo[MAXN], idx[MAXN], N, E, n_edge, dfs_time, road, city;
pair<int, int> store[MAXE];
stack<pair<int, int> > S;
vector<int> G[MAXN];

inline void add_edge(int u, int v)
{
	fo[n_edge] = u;
	to[n_edge] = v;
	ne[n_edge] = fin[u];
	fin[u] = n_edge++;

	fo[n_edge] = v;
	to[n_edge] = u;
	ne[n_edge] = fin[v];
	fin[v] = n_edge++;
	return;
}

void sol_bcc(int u, int v)
{
	// take a bi-conn component elem
	int tot = 0, nu, nv;
	pair<int, int> e;
	while (!S.empty())
	{
		e = S.top();
		S.pop();
		nu = e.first;
		nv = e.second;
		G[nu].clear();
		G[nv].clear();
		store[tot] = make_pair(nu, nv);
		tot++;
		if ((nu == u && nv == v) || (nu == v && nv == u))
		{
			break;
		}
	}

	if (tot <= 1)
	{
		return;// one edge
	}
	memset(col, 0, sizeof(col));
	for (int i = 0; i < tot; i++)
	{
		int nu = store[i].first;
		int nv = store[i].second;
		used[nu] = used[nv] = 1;
		G[nu].push_back(nv);
		G[nv].push_back(nu);
	}

	// chk odd cycle
	queue<int> Q;
	Q.push(nu);
	col[nu] = 1;
	while (!Q.empty())
	{
		nu = Q.front();
		Q.pop();
		for (int i = 0; i < (int)G[nu].size(); i++)
		{
			nv = G[nu][i];
			if (col[nv] == 0)
			{
				col[nv] = 3 - col[nu];
				Q.push(nv);
			}
			if (col[nu] == col[nv])
			{
				return;
			}
		}
	}
	road++;
}

void dfs(int u, int p)
{
	lo[u] = idx[u] = ++dfs_time;
	for (int i = fin[u]; i >= 0; i = ne[i])
	{
		int v = to[i];
		if (v == p)
		{
			continue;
		}
		if (idx[v] == 0)
		{
			S.push(make_pair(u, v));
			dfs(v, u);
			lo[u] = min(lo[u], lo[v]);
			if (lo[v] >= idx[u])
			{
				sol_bcc(u, v);
			}
		}
		else if (idx[v] < idx[u])
		{
			S.push(make_pair(u, v));
			lo[u] = min(lo[u], idx[v]);
		}
	}
	return;
}

void bcc()
{
	memset(idx, 0, sizeof(idx));
	memset(used, 0, sizeof(used));
	dfs_time = 0;
	road = 0;
	city = 0;
	for (int i = 0; i < N; i++)
	{
		if (idx[i])
		{
			continue;
		}
		dfs(i, i);
	}
	for (int i = 0; i < N; i++)
	{
		if (used[i] == 0)
		{
			road += 3;
			city += 2;
		}
	}
	return;
}

int main()
{
	int T, t = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &E);
		memset(fin, -1, sizeof(fin));
		n_edge = 0;
		int a, b;
		for (int i = 0; i < E; i++)
		{
			scanf("%d%d", &a, &b);
			add_edge(a, b);
		}
		bcc();
		printf("Case %d: %d %d\n", ++t, road, city);
	}
	return 0;
}
