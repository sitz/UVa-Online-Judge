#include <bits/stdc++.h>

using namespace std;

// 1,2,...,N: to form a matrix of R * N by stacking R stage permutation of N
// Find a single matrix when the maximum value of R.
// However, the matrix have to satisfy the following constraints:
// 	D[i][j] := (the number of j placed on the i-th column)
// 	E[i][j] := max(D[i][j]-C[i][j],0)
// and
// 	- With all i, Σ_j E[i][j] <= A[i]
// 	- In all j, Σ_i E[i][j] <= B[j]
// I flow to the flow numbers from column
// Send double each vertex representing a column vertices of digits,
// divided into parts which may or may not overflowing C

#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1 << 29;

// MAXFLOW //
const int V_MAX = 4 * 30 + 2;
const int E_MAX = 4 * 30 + 2 * 30 * 30;

template <class T>
struct graph
{
	int n, m, head[V_MAX], next[2 * E_MAX], to[2 * E_MAX];
	T capa[2 * E_MAX], flow[2 * E_MAX];

	void init(int N)
	{
		n = N;
		m = 0;
		rep(u, n) head[u] = -1;
	}

	void add_directed_edge(int u, int v, T ca)
	{
		next[m] = head[u];
		head[u] = m;
		to[m] = v;
		capa[m] = ca;
		flow[m] = 0;
		m++;
		next[m] = head[v];
		head[v] = m;
		to[m] = u;
		capa[m] = 0;
		flow[m] = 0;
		m++;
	}
};

int layer[V_MAX], now[V_MAX];

template <class T>
bool make_layer(const graph<T> &G, int s, int t)
{
	int n = G.n;
	rep(u, n) layer[u] = (u == s ? 0 : -1);
	int head = 0, tail = 0;
	static int Q[V_MAX];
	Q[tail++] = s;
	while (head < tail && layer[t] == -1)
	{
		int u = Q[head++];
		for (int e = G.head[u]; e != -1; e = G.next[e])
		{
			int v = G.to[e];
			T capa = G.capa[e], flow = G.flow[e];
			if (capa - flow > 0 && layer[v] == -1)
			{
				layer[v] = layer[u] + 1;
				Q[tail++] = v;
			}
		}
	}
	return layer[t] != -1;
}

template <class T>
T augment(graph<T> &G, int u, int t, T water)
{
	if (u == t)
	{
		return water;
	}
	for (int &e = now[u]; e != -1; e = G.next[e])
	{
		int v = G.to[e];
		T capa = G.capa[e], flow = G.flow[e];
		if (capa - flow > 0 && layer[v] > layer[u])
		{
			T w = augment(G, v, t, min(water, capa - flow));
			if (w > 0)
			{
				G.flow[e] += w;
				G.flow[e ^ 1] -= w;
				return w;
			}
		}
	}
	return 0;
}

template <class T>
T Dinic(graph<T> &G, int s, int t)
{
	int n = G.n;
	T ans = 0;
	while (make_layer(G, s, t))
	{
		rep(u, n) now[u] = G.head[u];
		for (T water = 1; water > 0; ans += water)
		{
			water = augment(G, s, t, INF);
		}
	}
	return ans;
}

// BIPARTITE MATCHING //
bool augment(int u, bool *vis, int match[2][V_MAX], const vector<int> *G)
{
	if (u == -1)
	{
		return true;
	}
	rep(i, G[u].size())
	{
		int v = G[u][i];
		if (!vis[v])
		{
			vis[v] = true;
			if (augment(match[1][v], vis, match, G))
			{
				match[0][u] = v;
				match[1][v] = u;
				return true;
			}
		}
	}
	return false;
}

int match[2][V_MAX];
int bipartite_matching(int L, int R, const vector<int> *G)
{
	rep(u, L) match[0][u] = -1;
	rep(v, R) match[1][v] = -1;
	int res = 0;
	static bool vis[V_MAX];
	rep(u, L)
	{
		rep(v, R) vis[v] = false;
		if (augment(u, vis, match, G))
		{
			res++;
		}
	}
	return res;
}
// LIBRARY END //

void solve()
{
	int n;
	scanf("%d", &n);
	int A[30], B[30], C[30][30];
	rep(i, n) scanf("%d", A + i);
	rep(i, n) scanf("%d", B + i);
	rep(i, n) rep(j, n) scanf("%d", C[i] + j);
	int s = 4 * n, t = s + 1;
	static graph<int> G;
	int lo = 0, hi = 150;
	while (lo < hi)
	{
		int mi = (lo + hi + 1) / 2, R = mi;
		G.init(4 * n + 2);
		rep(i, n)
		{
			G.add_directed_edge(s, i, R);
			G.add_directed_edge(3 * n + i, t, R);
			G.add_directed_edge(i, n + i, A[i]);
			G.add_directed_edge(2 * n + i, 3 * n + i, B[i]);
		}
		rep(i, n) rep(j, n)
		{
			G.add_directed_edge(i, 3 * n + j, C[i][j]);
			G.add_directed_edge(n + i, 2 * n + j, R);
		}
		if (Dinic(G, s, t) == n * R)
		{
			lo = mi;
		}
		else
		{
			hi = mi - 1;
		}
	}
	int R = lo;
	G.init(4 * n + 2);
	rep(i, n)
	{
		G.add_directed_edge(s, i, R);
		G.add_directed_edge(3 * n + i, t, R);
		G.add_directed_edge(i, n + i, A[i]);
		G.add_directed_edge(2 * n + i, 3 * n + i, B[i]);
	}
	rep(i, n) rep(j, n)
	{
		G.add_directed_edge(i, 3 * n + j, C[i][j]);
		G.add_directed_edge(n + i, 2 * n + j, R);
	}
	Dinic(G, s, t);
	// recovered ranks
	int D[30][30] = {};// D in question
	rep(u, 2 * n) for (int e = G.head[u]; e != -1; e = G.next[e])
	{
		int v = G.to[e];
		if (u < n)
		{
			if (3 * n <= v && v < 4 * n)
			{
				D[u][v - 3 * n] += G.flow[e];
			}
		}
		else
		{
			if (2 * n <= v && v < 3 * n)
			{
				D[u - n][v - 2 * n] += G.flow[e];
			}
		}
	}
	printf("%d\n", R);
	while (R--)
	{
		//Go to restore step-by-step to seek the perfect matching of the bipartite graph
		//Unknown why R times worth it be restored properly in this
		vector<int> BG[30];
		rep(i, n) rep(j, n) if (D[i][j] > 0)
		{
			BG[i].push_back(j);
		}
		bipartite_matching(n, n, BG);
		rep(i, n)
		{
			int j = match[0][i];
			D[i][j]--;
			printf("%d%c", j, i < n - 1 ? ' ' : '\n');
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case %d: ", cas), solve();
	}
	return 0;
}
