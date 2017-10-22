#include <bits/stdc++.h>

using namespace std;

const int MAXNODE = 1010;
const int oo = 0x3fffffff;

int N, M;
int graph[MAXNODE][MAXNODE];
int dist[MAXNODE], f[MAXNODE];

void init()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			graph[i][j] = oo;
			graph[i][i] = 0;
		}
}

void input()
{
	int a, b, d;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> d;
		a--;
		b--;
		graph[a][b] = graph[b][a] = d;
	}
}

void Dijkstra(int start)
{
	bool vis[N];
	for (int i = 0; i < N; i++)
	{
		dist[i] = graph[start][i];
		vis[i] = false;
	}
	dist[start] = 0;
	for (int i = 0; i < N; i++)
	{
		int mmin = oo;
		int k = 0;
		for (int j = 0; j < N; j++)
			if (!vis[j] && dist[j] < mmin)
			{
				mmin = dist[j];
				k = j;
			}
		vis[k] = true;
		for (int j = 0; j < N; j++)
			if (!vis[j] && dist[k] + graph[k][j] < dist[j])
			{
				dist[j] = dist[k] + graph[k][j];
			}
	}
}

int dfs(int x)
{
	if (x == 0)
	{
		return 1;
	}
	if (f[x] >= 0)
	{
		return f[x];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (graph[x][i] > 0 && graph[x][i] < oo)
		{
			int k = i;
			if (dist[k] > dist[x])
			{
				cnt += dfs(k);
			}
		}
	return f[x] = cnt;
}

int main()
{
	while (cin >> N && N)
	{
		cin >> M;
		init();
		input();
		Dijkstra(1);
		for (int i = 0; i < N; i++)
		{
			f[i] = -1;
		}
		cout << dfs(1) << endl;
	}
	return 0;
}
