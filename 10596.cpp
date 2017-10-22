#include <bits/stdc++.h>

using namespace std;

/**
 to check whether an undirected graph has an Eulerian tour or not,
 necessary and sufficient conditions for an undirected graph:
 an undirected graph has a closed Euler tour if it is connected,
 and each vertex has an even degree.
 use dfs to count # component
**/

bool check_deg(int n, const vector<int> &degs)
{
	for (int i = 0; i < n; i++)
	{
		if (degs[i] & 1)// vetex i ~ odd deg
		{
			return false;
		}
	}
	return true;
}

void dfs(int n, int i, const vector<vector<bool>> &graph, vector<bool> &visited)
{
	visited[i] = true;
	const vector<bool> &g = graph[i];
	for (int j = 0; j < n; j++)
	{
		if (g[j] && !visited[j])
		{
			dfs(n, j, graph, visited);
		}
	}
}

bool check_conn(int n, const vector<int> &degs, const vector<vector<bool>> &graph)
{
	// dfs to see if all vertices are connected
	vector<bool> visited(n, false);
	int start;
	for (start = 0; start < n; start++)
	{
		if (degs[start])
		{
			break;
		}
	}
	if (start < n)
	{
		dfs(n, start, graph, visited);
	}
	for (int i = 0; i < n; i++)
	{
		if (degs[i])
		{
			if (!visited[i])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n, r;
	while (scanf("%d%d", &n, &r) != EOF)
	{
		vector<int> degs(n, 0);
		vector<vector<bool>> graph(n, vector<bool>(n, false));
		for (int i = 0; i < r; i++)
		{
			int c1, c2;
			scanf("%d%d", &c1, &c2);
			degs[c1]++;
			degs[c2]++;
			graph[c1][c2] = graph[c2][c1] = true;
		}
		if (r && check_deg(n, degs) && check_conn(n, degs, graph))
		{
			printf("Possible\n");
		}
		else
		{
			printf("Not Possible\n");
		}
	}
	return 0;
}
