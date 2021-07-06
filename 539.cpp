#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 30;

int nNode, nEdge;
bool graph[MAXSIZE][MAXSIZE], visit[MAXSIZE][MAXSIZE];
int best;

void input()
{
	best = -1;
	memset(graph, 0, sizeof(graph));
	memset(visit, 0, sizeof(visit));
	for (int loop = 0; loop < nEdge; loop++)
	{
		int i, j;
		cin >> i >> j;
		graph[i][j] = graph[j][i] = true;
	}
}

void dfs(int node, int len)
{
	if (len > best)
	{
		best = len;
	}
	for (int i = 0; i < nNode; i++)
		if (graph[node][i] && !visit[node][i])
		{
			visit[node][i] = visit[i][node] = true;
			dfs(i, len + 1);
			visit[node][i] = visit[i][node] = false;
		}
}

void solve()
{
	for (int start = 0; start < nNode; start++)
	{
		dfs(start, 0);
	}
	cout << best << endl;
}

int main()
{
	while (cin >> nNode >> nEdge && nNode)
	{
		input();
		solve();
	}
	return 0;
}
