#include <bits/stdc++.h>

using namespace std;

#define MaxS 200010
#define MaxN 10010
#define MaxL 510
#define MaxM 1000010

char s[1010];
int child[MaxS][52], suffix[MaxS], end_[MaxS], q[MaxS], len[MaxN], dp[MaxL], sol[MaxL], rec[MaxL], g[MaxM], nxt[MaxM], head[MaxL], N, n, nodes, top;

int Code(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - 'a';
	}
	return ch - 'A' + 26;
}

void Build()
{
	memset(end_, -1, sizeof(end_));
	memset(child, 0, sizeof(child));
	nodes = 2;
	for (n = 0; gets(s); ++n)
	{
		if (!s[0])
		{
			return;
		}
		len[n] = strlen(s);
		int p = 1;
		for (int i = len[n] - 1; i >= 0; --i)
		{
			int ch = Code(s[i]);
			if (!child[p][ch])
			{
				child[p][ch] = nodes++;
			}
			p = child[p][ch];
		}
		end_[p] = n;
	}
}

void AC()
{
	int ql = 0, qr = 0;
	for (int i = 0; i < 52; ++i)
	{
		if (child[1][i])
		{
			q[qr++] = child[1][i];
			suffix[child[1][i]] = 1;
		}
		else
		{
			child[1][i] = 1;
		}
	}
	while (ql < qr)
	{
		int u = q[ql++];
		for (int i = 0; i < 52; ++i)
		{
			if (child[u][i])
			{
				q[qr++] = child[u][i];
				suffix[child[u][i]] = child[suffix[u]][i];
			}
			else
			{
				child[u][i] = child[suffix[u]][i];
			}
		}
	}
}

void addEdge(int a, int b)
{
	g[top] = b, nxt[top] = head[a], head[a] = top++;
}

void dfs(int dep, int u)
{
	if (dep == N)
	{
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = rec[i]; j < rec[i + 1]; ++j)
			{
				putchar(s[j]);
			}
			putchar(' ');
		}
		for (int j = rec[N - 1]; j < u; ++j)
		{
			putchar(s[j]);
		}
		puts("");
		return;
	}
	for (int i = head[u]; i; i = nxt[i])
	{
		rec[dep] = u;
		dfs(dep + 1, g[i]);
	}
}

void solve()
{
	while (gets(s))
	{
		if (!s[0])
		{
			return;
		}
		int l = strlen(s), p = 1;
		memset(head, 0, sizeof(head));
		top = 1;
		dp[l] = 0;
		sol[l] = 1;
		for (int i = l - 1; i >= 0; --i)
		{
			p = child[p][Code(s[i])];
			dp[i] = dp[i + 1] + 1;
			sol[i] = 0;
			for (int q = p; q != 1; q = suffix[q])
			{
				if (end_[q] != -1 && i + len[end_[q]] <= l && dp[i + len[end_[q]]] + 1 < dp[i])
				{
					dp[i] = dp[i + len[end_[q]]] + 1;
				}
			}
			for (int q = p; q != 1; q = suffix[q])
			{
				if (end_[q] != -1 && i + len[end_[q]] <= l && dp[i + len[end_[q]]] + 1 == dp[i])
				{
					sol[i] += sol[i + len[end_[q]]];
					addEdge(i, i + len[end_[q]]);
				}
			}
			if (dp[i] == dp[i + 1] + 1)
			{
				sol[i] += sol[i + 1];
				addEdge(i, i + 1);
			}
		}
		printf("%d %d\n", sol[0], dp[0]);
		N = dp[0];
		dfs(0, 0);
	}
}

int main()
{
	Build();
	AC();
	solve();
	return 0;
}
