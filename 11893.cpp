#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 400;

int in[N];

int edge[N][N];
int pn[N];
bool vis[N];
bool dis[N];
int mini[N], maxi[N];
int ord[N];

bool tsort(int n, int now, int &p, const int s, const int d)
{
	if (vis[now])
	{
		return dis[now];
	}
	vis[now] = true;
	rep(i, pn[now])
	{
		int next = edge[now][i];
		if (now == s && next == d)
		{
			continue;
		}
		if (!tsort(n, next, p, s, d))
		{
			return false;
		}
	}
	ord[p++] = now;
	dis[now] = true;
	return true;
}

bool dp(int n, const int s, const int d)
{
	rep(i, n) maxi[i] = 0;
	rep(i, n - 1)
	{
		int now = ord[i];
		rep(j, pn[now])
		{
			int next = edge[now][j];
			maxi[next] = max(maxi[next], maxi[now] + 1);
		}
	}
	return maxi[d] == n - 1;
}

bool solve(int n)
{
	rep(i, n)
	{
		if (pn[i] == 1 && in[edge[i][0]] == 1)
		{
			int p = 0;
			rep(j, n) vis[j] = false, dis[j] = false;
			if (!tsort(n, edge[i][0], p, i, edge[i][0]))
			{
				continue;
			}
			reverse(ord, ord + n);
			if (dp(n, edge[i][0], i))
			{
				return true;
			}
		}
	}
	return false;
}

main()
{
	int te;
	scanf("%d", &te);
	while (te--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		rep(i, n) pn[i] = 0, in[i] = 0;
		rep(i, m)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			edge[f][pn[f]++] = t;
			in[t]++;
		}
		if (m >= n && solve(n))
		{
			printf("Yeah, I'm superman\n");
		}
		else
		{
			printf("Your DAGy was initially defected!\n");
		}
	}
	return false;
}
