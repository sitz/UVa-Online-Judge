#include <bits/stdc++.h>

using namespace std;

#define N 1010

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

vector<int> edges[N], rEdges[N], sortedNode;
bool vis[N];

void reset()
{
	For(i, 0, N)
	{
		edges[i].clear();
		rEdges[i].clear();
	}
	sortedNode.clear();
	Set(vis, false);
}

void dfs1(int x)
{
	vis[x] = true;
	Fors(u, edges[x]) if (!vis[edges[x][u]])
	{
		dfs1(edges[x][u]);
	}
	sortedNode.push_back(x);
}

void dfs2(int x)
{
	vis[x] = false;
	Fors(u, rEdges[x]) if (vis[rEdges[x][u]])
	{
		dfs2(rEdges[x][u]);
	}
}

int main(int argc, char **argv)
{
	int p, t;
	while (scanf("%d%d", &p, &t))
	{
		if (p == 0 && t == 0)
		{
			break;
		}
		getchar();
		reset();
		char name[100], name1[100], name2[100];
		map<string, int> name_index;
		For(i, 1, p + 1)
		{
			gets(name);
			name_index[name] = i;
		}
		For(i, 0, t)
		{
			gets(name1);
			gets(name2);
			edges[name_index[name1]].push_back(name_index[name2]);
			rEdges[name_index[name2]].push_back(name_index[name1]);
		}
		For(i, 1, p + 1) if (!vis[i])
		{
			dfs1(i);
		}
		int c = 0;
		for (int i = sortedNode.size() - 1; i >= 0; i--)
		{
			if (vis[sortedNode[i]])
			{
				dfs2(sortedNode[i]);
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
