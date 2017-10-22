#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 10;

struct Edge
{
	int to, next;
} edge[maxn];

int head[maxn], dfn[maxn], B[maxn << 2], F[maxn << 2], d[maxn << 2][20], pos[maxn << 2];
int E, Time, tot;

void newedge(int u, int to)
{
	edge[E].to = to;
	edge[E].next = head[u];
	head[u] = E++;
}

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		head[i] = -1;
		dfn[i] = 0;
	}
	E = Time = tot = 0;
}

void rmq_init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = B[i];
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + j - 1 <= n; i++)
		{
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
		}
}

int rmq(int L, int R)
{
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1)
	{
		k++;
	}
	return min(d[L][k], d[R - (1 << k) + 1][k]);
}

int lca(int a, int b)
{
	if (pos[a] > pos[b])
	{
		swap(a, b);
	}
	int ans = rmq(pos[a], pos[b]);
	return F[ans];
}

int st[maxn];
void dfs()
{
	int top = 0;
	st[++top] = 0;
	while (top)
	{
		int u = st[top];
		if (!dfn[u])
		{
			dfn[u] = ++Time;
			F[Time] = u;
			pos[u] = tot + 1;
		}
		B[++tot] = dfn[u];
		bool flag = 0;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int to = edge[i].to;
			if (!dfn[to])
			{
				flag = 1;
				st[++top] = to;
				break;
			}
		}
		if (!flag)
		{
			top--;
		}
	}
}

int c[maxn], n;

int bin(int l, int r, int val)
{
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (c[mid] >= val)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return r;
}

void solve()
{
	dfs();
	rmq_init(tot);
	int m, u, to;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &u, &to);
		if (u >= n)
		{
			puts("No");
			continue;
		}
		if (u == to)
		{
			puts("No");
			continue;
		}
		int k = bin(0, n - 1, to);
		if (lca(u, k) == u)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
}

int main()
{
	int t, m, cas = 1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		init(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &c[i]);
		}
		for (int i = 1; i < n; i++)
		{
			c[i] += c[i - 1];
		}
		for (int i = 1; i < n; i++)
		{
			int k = bin(0, n - 1, i);
			newedge(k, i);
		}
		printf("Case %d:\n", cas++);
		solve();
		if (t)
		{
			puts("");
		}
	}
	return 0;
}
