#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4;

int N;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];

void init()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		graph[i].clear();
	}
	for (int i = 0; i < N; i++)
	{
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			graph[i].push_back(x);
		}
	}
}

void dfs(int v)
{
	visited[v] = true;
	for (int i = 0; i < (int)graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!visited[u])
		{
			dist[u] = dist[v] + 1;
			dfs(u);
		}
	}
}

int sub()
{
	memset(visited, false, sizeof(visited));
	dist[0] = 0;
	dfs(0);
	int p = max_element(dist, dist + N) - dist;
	memset(visited, false, sizeof(visited));
	dist[p] = 0;
	dfs(p);
	return *max_element(dist, dist + N);
}

int solve()
{
	return 2 * N - 2 - sub();
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
