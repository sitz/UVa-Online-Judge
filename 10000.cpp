#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define SZ(a) ((int)(a).size())

typedef struct _node
{
	int n, length;
	vector<int> adj;
} node;

static vector<node> G;
static pair<int, int> result;
static int n, start, a, b, counter = 0;

void dfs(int start, int length)
{
	if (G[start - 1].length > length)
	{
		return;
	}
	else if (G[start - 1].length < length)
	{
		G[start - 1].length = length;
	}
	if (G[start - 1].adj.empty())
	{
		if (length > result.first)
		{
			result.first = length;
			result.second = start;
		}
		else if (length == result.first)
		{
			if (start < result.second)
			{
				result.second = start;
			}
		}
	}
	else
	{
		int end = SZ(G[start - 1].adj);
		FOR(i, 0, end)
		{
			dfs(G[start - 1].adj[i], length + 1);
		}
	}
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		G.clear();
		counter++;
		FOREQ(i, 1, n)
		{
			node N;
			N.n = i;
			N.length = 0;
			G.push_back(N);
		}
		scanf("%d", &start);
		while (scanf("%d%d", &a, &b) && a && b)
		{
			G[a - 1].adj.push_back(b);
		}
		result.first = 0;
		result.second = 0;
		dfs(start, 0);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
					 counter, start, result.first, result.second);
	}
	return 0;
}
