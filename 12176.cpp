#include <bits/stdc++.h>

using namespace std;

// method : MST (Kruskal's), disjoint sets (Union-Find), depth-first search (DFS)
// runtime: O(E*log(V) + Q*V), V = # of nodes, E = # of edges, Q = # of queries

typedef pair<int, int> ii;
typedef vector<ii> vii;

// MAXN = max number of places, MAXR = max number of roads
const int MAXN = 3000, MAXR = 100000;

// V = number of vertices, E = number of edges
// fr[i] = starting point of edge i, to[i] = end point of edge i, len[i] = length of edge i
// ord[i] = index of the i-th shortest edge
// up[i] = parent of node i in Union-Find
// adj[i] = vector of minimum spanning tree edges incident to node i
// adj[i][j].first = adjacent node, adj[i][j].second = length
int V, E;
int fr[MAXR], to[MAXR], len[MAXR];
int ord[MAXR];
int up[MAXN];
vii adj[MAXN];

// only used for sorting edges by length
bool cmp(int a, int b)
{
	return len[a] < len[b];
}

// the "find" part of Union-Find, with path compression
int root(int k)
{
	return up[k] < 0 ? k : (up[k] = root(up[k]));
}

// the "union" part of Union-Find, with weighted union
bool join(int k, int m)
{
	if ((k = root(k)) == (m = root(m)))
	{
		return false;
	}
	if (up[k] < up[m])
	{
		up[k] += up[m];
		up[m] = k;
	}
	else
	{
		up[m] += up[k];
		up[k] = m;
	}
	return true;
}

// ordinary implementation of Kruskal's algorithm
void kruskal()
{
	sort(ord, ord + E, cmp);
	memset(up, -1, sizeof up);
	for (int i = 0; i < V; ++i)
	{
		adj[i].clear();
	}
	for (int i = V - 1, j = 0; i > 0; ++j)
	{
		int a = fr[ord[j]], b = to[ord[j]];
		if (join(a, b))
		{
			// store a chosen edge for later depth-first search
			adj[a].push_back(ii(b, len[ord[j]]));
			adj[b].push_back(ii(a, len[ord[j]]));
			--i;
		}
	}
}

// depth-first search inside the minimum spanning tree
// return longest edge on unique path between s and t
// u is the node where we come from (given to avoid going back)
int dfs(int s, int t, int u)
{
	if (s == t)
	{
		return 0;
	}
	for (vii::iterator it = adj[s].begin(); it != adj[s].end(); ++it)
	{
		int re;
		if (it->first != u && (re = dfs(it->first, t, s)) >= 0)
		{
			return max(re, it->second);
		}
	}
	return -1;
}

int main()
{
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; ++kase)
	{
		cin >> V >> E;
		for (int i = 0; i < E; ++i)
		{
			cin >> fr[i] >> to[i] >> len[i];
			--fr[i];
			--to[i];
			ord[i] = i;
		}
		// compute an arbitrary minimum spanning tree
		kruskal();
		cout << "Case " << kase << endl;
		int k, a, b;
		for (cin >> k; k > 0; --k)
		{
			cin >> a >> b;
			// find longest edge by depth-first searching in that tree
			cout << dfs(--a, --b, -1) << endl;
		}
		cout << endl;
	}
	return 0;
}
