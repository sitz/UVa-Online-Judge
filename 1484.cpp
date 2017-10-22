#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int N = 500005;

int n, l, r, dp[N], E, fst[N], nxt[N];

struct Edge
{
	int u, v, w;
} edge[N];

inline void scanf_(int &num)
{
	char in;
	while ((in = getchar()) > '9' || in < '0')
		;
	num = in - '0';
	while (in = getchar(), in >= '0' && in <= '9')
	{
		num *= 10, num += in - '0';
	}
}

void dfs(int u, int fa, int sum, int who)
{
	if (who && fst[u] != -1)
	{
		dp[u] = INF;
	}
	else
	{
		dp[u] = 0;
	}
	for (int i = fst[u]; i != -1; i = nxt[i])
	{
		int v = edge[i].v, w = edge[i].w;
		if (v == fa)
		{
			continue;
		}
		dfs(v, u, sum + w, 1 - who);
		if (who == 0 && dp[v] + w + sum >= l && dp[v] + w + sum <= r)
		{
			dp[u] = max(dp[u], dp[v] + w);
		}
		if (who == 1 && dp[v] + w + sum >= l && dp[v] + w + sum <= r)
		{
			dp[u] = min(dp[u], dp[v] + w);
		}
	}
}

void add(int u, int v, int w)
{
	edge[E].u = u;
	edge[E].v = v;
	edge[E].w = w;
	nxt[E] = fst[u];
	fst[u] = E++;
}

int main()
{
	while (~scanf("%d%d%d", &n, &l, &r))
	{
		E = 0;
		memset(fst, -1, sizeof(fst));
		int u, v, w;
		for (int i = 0; i < n - 1; i++)
		{
			scanf_(u);
			scanf_(v);
			scanf_(w);
			add(u, v, w);
		}
		dfs(0, -1, 0, 0);
		if (dp[0] < l || dp[0] > r)
		{
			printf("Oh, my god!\n");
		}
		else
		{
			printf("%d\n", dp[0]);
		}
	}
	return 0;
}
