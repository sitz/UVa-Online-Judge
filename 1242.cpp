#include <bits/stdc++.h>

using namespace std;

#define N 10005
#define NV i->first
#define p Q.front()

int karp(map<int, int> *, map<int, int> *, int, int);
int bfs(map<int, int> *, map<int, int> *, int[], int, int);

int karp(map<int, int> adj[], map<int, int> cap[], int s, int t)
{
	int prev[N] = {0}, f, df;

	for (f = 0; df = bfs(adj, cap, prev, s, t); ++f)
		for (int i = prev[t], j = t; i != j; i = prev[j = i])
			adj[i][j] += df, adj[j][i] -= df;

	return f;
}

int bfs(map<int, int> adj[], map<int, int> cap[], int prev[], int s, int t)
{
	queue<int> Q;
	bool vis[N] = {true};
	int current[N] = {INT_MAX};

	for (Q.push(s); !Q.empty(); Q.pop())
	{
		for (map<int, int>::iterator i = adj[p].begin(); i != adj[p].end(); ++i)
			if (!vis[NV] && cap[p][NV] - adj[p][NV])
			{
				vis[NV] = true;
				current[NV] = min(current[p], cap[p][NV] - adj[p][NV]);
				prev[NV] = p;
				if (NV == t)
					return current[t];
				else
					Q.push(NV);
			}
	}
	return 0;
}

int main()
{
	for (int t = 0, V, E, S, T; scanf("%d%d", &V, &E) && V;)
	{
		map<int, int> adj[V + 1], cap[V + 1];

		for (int i = 0, a, b; i < E; ++i)
		{
			scanf("%d%d", &a, &b);
			adj[a][b], ++cap[a][b];
			adj[b][a], ++cap[b][a];
		}
		scanf("%d%d", &S, &T);
		adj[0][S], cap[0][S] = 2;

		printf("Case %d: %s\n", ++t, karp(adj, cap, 0, T) == 2 ? "YES" : "NO");
	}
	return 0;
}
