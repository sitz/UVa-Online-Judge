#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define INF 0x3f3f3f3f
#define MAXN 1048576

struct Node
{
	int l, r;
	int face;
} nodes[MAXN];

int F[MAXN], used[MAXN];

void rm_node(int idx)
{
	used[idx] = 1;
	nodes[nodes[idx].r].l = nodes[idx].l;
	nodes[nodes[idx].l].r = nodes[idx].r;
}

int main()
{
	int T, cases = 0, L, P, x, y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &L, &P);
		for (int i = 0; i < L; i++)
		{
			nodes[i].l = i - 1, nodes[i].r = i + 1, F[i] = 0, used[i] = 0;
		}
		nodes[0].l = L - 1, nodes[L - 1].r = 0;
		for (int i = 0; i < P; i++)
		{
			scanf("%d%d", &x, &y);
			nodes[x].face = y;
			nodes[y].face = x;
			F[x] = 1, F[y] = -1;
		}
		int st = 0, lst_sz = 2 * P;
		for (int i = 0; i < L; i++)
		{
			if (!F[i])
			{
				rm_node(i);
			}
		}
		while (lst_sz)
		{
			int update = 0;
			while (used[st])
			{
				st++;
			}
			for (int i = nodes[st].r; !update && i != st; i = nodes[i].r)
			{
				x = i, y = nodes[i].r;
				if (F[x] == F[y] && (nodes[nodes[y].face].r == nodes[x].face ||
														 nodes[nodes[x].face].r == nodes[y].face))
				{
					rm_node(x), rm_node(nodes[x].face);
					rm_node(y), rm_node(nodes[y].face);
					lst_sz -= 4;
					update = 1;
				}// pass
				else if (y == nodes[x].face)
				{
					rm_node(x), rm_node(y);
					lst_sz -= 2;
					update = 1;
				}// self-loop
			}
			if (!update)
			{
				break;
			}
		}
		printf("Case #%d: %s\n", ++cases, lst_sz ? "NO" : "YES");
	}
	return 0;
}
