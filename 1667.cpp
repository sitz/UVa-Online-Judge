#include <bits/stdc++.h>

using namespace std;

#define MAXN 64

int g[MAXN][MAXN];

// during every iteration each leaf is contracted with its parent, until
// * 1 leaf left
// * 2 leaves left, and they connected by a single edge
// a vertex i is a leaf only when d[j][i]+d[i][k]>d[j][k] for all vertices j, k.
// if a leaf i is still a leaf(instead of becoming an internal node) after contraction, then there is a router with degree n+2, where n is the number of vertices having zero distance with i.
// special case: router's degree is n+1 if it is the final iteration, ending with condition 1 above
int is_leaf(int N, int x, int used[])
{
	int ret = 1;
	for (int j = 0; j < N && ret; j++)
	{
		for (int k = 0; k < N && ret; k++)
		{
			if (used[j] || used[k])// 0: leaf, 1: inner, 2: del
			{
				continue;
			}
			if (j == k || x == j || x == k)
			{
				continue;
			}
			ret &= g[j][x] + g[x][k] > g[j][k];
		}
	}
	return ret;
}

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &g[i][j]);
			}
		}
		int used[MAXN] = {};
		vector<int> ret;
		while (true)
		{
			vector<int> leaf;
			for (int i = 0; i < N; i++)
			{
				if (used[i] == 2)// del
				{
					continue;
				}
				int b = is_leaf(N, i, used);
				if (b)
				{
					leaf.push_back(i);
				}
				else
				{
					used[i] = 1;
				}
			}
			int x = leaf[0];
			for (int i = 0; i < N; i++)
			{
				if (i == x)
				{
					continue;
				}
				if (g[x][i])
				{
					g[x][i]--;
					g[i][x]--;
				}
			}
			if (is_leaf(N, x, used))
			{
				int router = 0;
				for (int i = 0; i < N; i++)
				{
					if (used[i] == 2 || i == x)
					{
						continue;
					}
					if (g[x][i] == 0)
					{
						router++;
						used[i] = 2;
					}
				}
				ret.push_back(router + 2);
			}
			if (leaf.size() == 1 || (leaf.size() == 2 && g[leaf[0]][leaf[1]] == 1))
			{
				break;
			}
		}
		sort(ret.begin(), ret.end());
		for (int i = 0; i < ret.size(); i++)
		{
			printf("%d%c", ret[i], i == ret.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
