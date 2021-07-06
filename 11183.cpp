#include <bits/stdc++.h>

using namespace std;

const int mm = 44444;
const int mn = 1111;

struct edge
{
	int s, t, w;
} g[mm], h[mm];

bool huan;
int head[mm], nxt[mm], p[mn], q[mn], mark[mn], fp[mn], from[mn], vis[mn], in[mn], w[mn], ans, sum, i, j, k, n, m, e, r, mw, t, cas = 0;

inline void addedge(int u, int v, double c)
{
	g[e].s = u, g[e].t = v, g[e].w = c, nxt[e] = head[u], head[u] = e++;
	if (c > mw)
	{
		mw = c;
	}
}
void dfs(int u)
{
	++sum, vis[u] = 1;
	for (int i = head[u]; i >= 0; i = nxt[i])
		if (!vis[g[i].t])
		{
			dfs(g[i].t);
		}
}
inline void init(int &a)
{
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	for (a = 0; ch >= '0' && ch <= '9'; ch = getchar())
	{
		a = a * 10 + ch - 48;
	}
}
void mysort()
{
	int i;
	for (i = 0; i <= n; ++i)
	{
		q[i] = 0;
	}
	for (i = 0; i <= mw; ++i)
	{
		p[i] = 0;
	}
	for (i = 0; i < e; ++i)
	{
		++q[g[i].t], ++p[g[i].w];
	}
	for (i = 1; i <= n; ++i)
	{
		q[i] += q[i - 1];
	}
	for (i = n; i > 0; --i)
	{
		q[i] = q[i - 1];
	}
	q[0] = 0;
	for (i = 1; i <= mw; ++i)
	{
		p[i] += p[i - 1];
	}
	for (i = mw; i > 0; --i)
	{
		p[i] = p[i - 1];
	}
	p[0] = 0;
	for (i = 0; i < e; ++i)
	{
		h[p[g[i].w]++] = g[i];
	}
	for (i = 0; i < e; ++i)
	{
		g[q[h[i].t]++] = h[i];
	}
}
int main()
{
	init(t);
	while (t--)
	{
		init(n), init(m), --n;
		for (i = e = mw = 0; i <= n; ++i)
		{
			head[i] = -1;
		}
		while (m--)
		{
			init(i), init(j), init(k);
			if (i != j)
			{
				addedge(i, j, k);
			}
		}
		for (sum = i = 0; i <= n; ++i)
		{
			vis[i] = 0;
		}
		dfs(0);
		if (sum < n + 1)
		{
			printf("Case #%d: Possums!\n", ++cas);
			continue;
		}
		mysort();
		for (i = 0; i <= n; ++i)
		{
			fp[i] = p[i] = -1, in[i] = vis[i] = 0, mark[i] = i;
		}
		for (i = 0; i < e; ++i)
			if (p[g[i].t] < 0)
			{
				p[g[i].t] = i;
			}
		huan = 1, ans = sum = 0;
		while (huan)
		{
			huan = 0;
			for (i = 1; i <= n; ++i)
				if (fp[j = mark[i]] >= 0)
				{
					if (fp[i] < 0)
					{
						in[i] += w[j], mark[i] = mark[mark[i]];
					}
					else
					{
						in[i] += w[i], ans += w[i];
						if (g[++p[fp[i]]].t != fp[i])
						{
							p[fp[i]] = -1;
						}
					}
				}
			for (i = 0; i <= n; ++i)
			{
				fp[i] = -1, vis[i] = 0;
			}
			for (i = 1; i <= n; ++i)
				if (p[i] >= 0)
				{
					if (fp[j = mark[i]] < 0 || (fp[j] >= 0 && w[j] > g[p[i]].w - in[i]))
					{
						w[j] = g[p[i]].w - in[i], fp[j] = i, from[j] = mark[g[p[i]].s];
					}
				}
			for (sum = 0, i = 1; i <= n; ++i)
				if (fp[i] >= 0)
				{
					sum += w[i];
				}
			for (i = 1; i <= n; ++i)
				if (!vis[i])
				{
					r = 0, j = i;
					while (j > 0 && vis[j] >= 0)
					{
						if (vis[j] > 0)
						{
							huan = 1;
							while (q[--r] != j)
							{
								mark[q[r]] = j, vis[q[r]] = -1;
							}
							vis[j] = -1;
						}
						else if (!vis[j])
						{
							vis[q[r++] = j] = 1;
						}
						if (fp[j] >= 0)
						{
							j = from[j];
						}
						else
						{
							j = -1;
						}
					}
					while (r--)
					{
						vis[q[r]] = fp[q[r]] = -1;
					}
				}
		}
		printf("Case #%d: %d\n", ++cas, ans + sum);
	}
	return 0;
}
