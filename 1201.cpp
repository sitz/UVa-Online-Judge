#include <bits/stdc++.h>

using namespace std;

const int maxn = 550;

struct Edge
{
	int from, to;
	int next;
} edge[maxn * maxn];

struct BPM
{
	int n, m;
	int head[maxn];
	int left[maxn];
	bool T[maxn];
	int cnt;

	void init(int n)
	{
		this->n = n;
		cnt = 0;
		memset(head, -1, sizeof(head));
	}

	void AddEdge(int u, int v)
	{
		edge[cnt].from = u, edge[cnt].to = v;
		edge[cnt].next = head[u];
		head[u] = cnt++;
	}

	bool match(int u)
	{
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!T[v])
			{
				T[v] = true;
				if (left[v] == -1 || match(left[v]))
				{
					left[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	void solve()
	{
		memset(left, -1, sizeof(left));
		int ans = 0;
		for (int u = 1; u <= n; u++)
		{
			memset(T, 0, sizeof(T));
			if (match(u))
			{
				ans++;
			}
		}
		printf("%d\n", n - ans);
	}
};

int n, t[maxn], dis[maxn], s[maxn][2], e[maxn][2];
BPM solver;

bool judge(int i, int j)
{
	int x = abs(e[i][0] - s[j][0]) + abs(e[i][1] - s[j][1]);
	if (t[j] > t[i] + dis[i] + x)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int i, j;
		scanf("%d", &n);
		solver.init(n);
		for (i = 1; i <= n; i++)
		{
			int h, m;
			int a, b, c, d;
			scanf("%d:%d %d %d %d %d", &h, &m, &a, &b, &c, &d);
			t[i] = h * 60 + m;
			dis[i] = abs(a - c) + abs(b - d);
			s[i][0] = a, s[i][1] = b;
			e[i][0] = c, e[i][1] = d;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (judge(i, j))
					solver.AddEdge(i, j);
			}
		}
		solver.solve();
	}
	return 0;
}
