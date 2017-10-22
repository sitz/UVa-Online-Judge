#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

const int NN = 128;

struct edge
{
	int nxt, to;
} e[NN * NN];

bool v[NN];
int ecnt, nxt[NN], value[NN];

void add_edge(int a, int b)
{
	edge &E = e[ecnt];
	E.to = b;
	E.nxt = nxt[a];
	nxt[a] = ecnt++;
}

void read_edge()
{
	int from, to;
	scanf("%d %d", &from, &to);
	add_edge(from, to);
}

int main()
{
	int learned(0);
	scanf("%*d");
	for (int cnum = 0, m, n; scanf("%d %d", &n, &m) == 2; learned = 0)
	{
		FOR(i, n)
		{
			scanf("%d", value + i);
			nxt[i] = -1;
			v[i] = false;
		}
		ecnt = 0;
		FOR(i, m)
		read_edge();
		int u(0), v(0), w(-1);
		while (1)
		{
			u = v;
			learned += value[u];
			for (int at = nxt[u]; at != -1; at = e[at].nxt)
			{
				if (value[e[at].to] > w)
				{
					w = value[v = e[at].to];
				}
			}
			if (u == v)
			{
				break;
			}
			w = -1;
		}
		printf("Case %d: %d %d\n", ++cnum, learned, u);
	}
	return 0;
}
