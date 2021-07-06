#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;
const int maxm = 300005;

struct TwoSAT
{
	int n, s[maxn * 2], c;
	bool mark[maxn * 2];
	vector<int> g[maxn * 2];

	void init(int n)
	{
		this->n = n;
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < 2 * n; i++)
			g[i].clear();
	}

	void addClause(int x, int xflag, int y, int yflag)
	{
		x = x * 2 + xflag;
		y = y * 2 + yflag;
		g[x ^ 1].push_back(y);
		g[y ^ 1].push_back(x);
	}

	bool dfs(int u)
	{
		if (mark[u ^ 1])
			return false;
		if (mark[u])
			return true;
		mark[u] = true;
		s[c++] = u;

		for (int i = 0; i < g[u].size(); i++)
			if (!dfs(g[u][i]))
				return false;
		return true;
	}

	bool solve()
	{
		for (int i = 0; i < 2 * n; i += 2)
		{
			if (!mark[i] && !mark[i + 1])
			{
				c = 0;
				if (!dfs(i))
				{
					while (c)
						mark[s[--c]] = false;
					if (!dfs(i + 1))
						return false;
				}
			}
		}
		return true;
	}
} solver;

const int dx[][2] = {{0, 1}, {1, 0}};
const int dy[][2] = {{0, 1}, {0, 1}};

int N, idx[maxn], X[maxn], Y[maxn], F[maxn], C[maxn];
int M, L[maxm], R[maxm], W[maxm];
int E, first[maxn], jump[maxm * 2], link[maxm * 2], val[maxm * 2];

inline int find(int x) { return x == F[x] ? x : F[x] = find(F[x]); }
inline int distance(int a, int b) { return abs(X[a] - X[b]) + abs(Y[a] - Y[b]); }
inline void addEdge(int u, int v, int w)
{
	jump[E] = first[u];
	link[E] = v;
	val[E] = w;
	first[u] = E++;
}

void init()
{
	E = 0;
	memset(first, -1, sizeof(first));

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &X[i], &Y[i]);
		F[i] = i, C[i] = 1;
	}

	int u, v;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &W[i]);
		L[i] = --u;
		R[i] = --v;
		if (find(u) != find(v))
		{
			C[find(v)] += C[find(u)];
			F[find(u)] = find(v);
		}
		addEdge(u, v, W[i]);
		addEdge(v, u, W[i]);
	}
}

bool draw(int u, int c)
{
	if (idx[u] != -1)
		return idx[u] == c;
	idx[u] = c;
	for (int i = first[u]; i != -1; i = jump[i])
	{
		int v = link[i], w = val[i];
		if (!draw(v, c ^ ((distance(u, v) & 1) ^ (w & 1))))
			return false;
	}
	return true;
}

bool judge(int u, int k)
{
	memset(idx, -1, sizeof(idx));
	if (!draw(u, k))
		return false;
	solver.init(N);

	for (int i = 0; i < M; i++)
	{
		if (find(L[i]) != u || find(R[i]) != u)
			continue;
		for (int p = 0; p < 2; p++)
		{
			for (int q = 0; q < 2; q++)
			{
				int x0 = X[L[i]] + dx[idx[L[i]]][p];
				int y0 = Y[L[i]] + dy[idx[L[i]]][p];
				int x1 = X[R[i]] + dx[idx[R[i]]][q];
				int y1 = Y[R[i]] + dy[idx[R[i]]][q];
				if (abs(x0 - x1) + abs(y0 - y1) != W[i])
					solver.addClause(L[i], p, R[i], q);
			}
		}
	}
	return solver.solve();
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		init();
		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			if (i != F[i])
			{
				continue;
			}
			if (!judge(i, 0) && !judge(i, 1))
			{
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? "possible" : "impossible");
	}
	return 0;
}
