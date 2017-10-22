#include <bits/stdc++.h>

using namespace std;

struct edge {int nxt, to;} e[80048];
enum {BLANK, BLUE, RED};

int ecnt, cnt[3], color[256], nxt[256];

void add_edge(int from, int to)
{
	edge &E = e[ecnt];
	E.nxt = nxt[from];
	E.to = to;
	nxt[from] = ecnt++;
}

bool bicolor(int u, int c)
{
	bool r = true;
	color[u] = c;
	++cnt[c];
	for (int at = nxt[u], v; at != -1; at = e[at].nxt)
	{
		v = e[at].to;
		if (color[v] == BLANK)
		{
			r &= bicolor(v, 3 - c);
		}
		else
		{
			r &= color[v] == 3 - c;
		}
	}
	return r;
}

int main()
{
	scanf("%*d");
	for (int n; scanf("%d", &n) == 1;)
	{
		int max_inv = 0;
		ecnt = 0;
		for (int i = 0; i < n; ++i)
		{
			nxt[i] = -1;
			color[i] = BLANK;
		}
		for (int enemies, i = 0, to; i < n; ++i)
		{
			scanf("%d", &enemies);
			while (enemies--)
			{
				scanf("%d", &to);
				--to;
				if (to < n)
				{
					add_edge(i, to);
					add_edge(to, i);
				}
			}
		}
		for (int i = 0; i < n; ++i)
			if (color[i] == BLANK)
			{
				cnt[RED] = cnt[BLUE] = 0;
				if (!bicolor(i, BLUE))
				{
					continue;
				}
				max_inv += cnt[BLUE] < cnt[RED] ? cnt[RED] : cnt[BLUE];
			}
		printf("%d\n", max_inv);
	}
	return 0;
}
