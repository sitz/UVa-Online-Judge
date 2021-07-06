#include <bits/stdc++.h>

using namespace std;

#define M 1010
#define N 1010

bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int visitL[M], visitR[N];
int n, m, l;
int minShot;

bool bpm(int u)
{
	for (int v = 1; v <= n; v++)
		if (graph[u][v])
		{
			if (seen[v])
			{
				continue;
			}
			seen[v] = true;
			if (matchR[v] < 0 || bpm(matchR[v]))
			{
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	return false;
}

void input()
{
	memset(graph, false, sizeof(graph));
	int x, y, i;
	for (i = 0; i < l; i++)
	{
		scanf("%d%d", &x, &y);
		graph[x][y] = true;
	}
}

void dfs(int u)
{
	if (visitL[u])
	{
		return;
	}
	visitL[u] = true;
	for (int v = 1; v <= n; v++)
		if (graph[u][v] && !visitR[v])
		{
			visitR[v] = true;
			dfs(matchR[v]);
		}
}

void output()
{
	memset(visitL, 0, sizeof(visitL));
	memset(visitR, 0, sizeof(visitR));
	for (int x = 1; x <= m; x++)
		if (matchL[x] == -1)
		{
			dfs(x);
		}
	printf("%d", minShot);
	for (int i = 1; i <= m; i++)
		if (!visitL[i])
		{
			printf(" r%d", i);
		}
	for (int j = 1; j <= n; j++)
		if (visitR[j])
		{
			printf(" c%d", j);
		}
	printf("\n");
}

void solve()
{
	memset(matchL, -1, sizeof(matchL));
	memset(matchR, -1, sizeof(matchR));
	minShot = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(seen, 0, sizeof(seen));
		if (bpm(i))
		{
			minShot++;
		}
	}
}

int main()
{
	while (scanf("%d%d%d", &m, &n, &l) != EOF && m)
	{
		input();
		solve();
		output();
	}
	return 0;
}
