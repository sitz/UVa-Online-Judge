#include <bits/stdc++.h>

using namespace std;

const int NODE = 100 + 1, EMPTY = 0, W = 1, B = 2;

bool adj[NODE][NODE];
int color[NODE][NODE];

inline int rev(int c)
{
	return c == W ? B : W;
}

bool rec(int src, int dst, int size, int c)
{
	color[src][dst] = color[dst][src] = c;
	for (int nxt = 0; nxt < size; ++nxt)
	{
		if (nxt == src || nxt == dst)
		{
			continue;
		}
		if (adj[src][dst] + adj[dst][nxt] + adj[nxt][src] == 3)
		{
			if (color[dst][nxt] == rev(c))
			{
				return false;
			}
			if (color[dst][nxt] == EMPTY && !rec(dst, nxt, size, c))
			{
				return false;
			}
		}
		if (adj[src][dst] + adj[dst][nxt] + adj[nxt][src] == 2)
		{
			int tmp = adj[dst][nxt] ? dst : src;
			if (color[tmp][nxt] == c)
			{
				return false;
			}
			if (color[tmp][nxt] == EMPTY && !rec(tmp, nxt, size, rev(c)))
			{
				return false;
			}
		}
	}
	return true;
}

bool coloring(int size)
{
	fill(&color[0][0], &color[size - 1][size], EMPTY);
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (adj[i][j] && color[i][j] == EMPTY && !rec(i, j, size, W))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int node, edge;
	while (scanf("%d%d", &node,&edge) == 2)
	{
		if (node + edge == 0)
		{
			break;
		}
		fill(&adj[0][0], &adj[node - 1][node], false);
		int src, dst, cnt = 0;
		for (int i = 0; i < edge; ++i)
		{
			scanf("%d%d", &src,&dst);
			adj[src][dst] = adj[dst][src] = true;
		}
		printf(coloring(node) ? "YES\n" : "NO\n");
	}
	return 0;
}
