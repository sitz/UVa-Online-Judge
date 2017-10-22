#include <bits/stdc++.h>

using namespace std;

#define maxn 1005

char color[maxn], mark[maxn], Fg[maxn], taken[maxn], links[1001][1001];
int N, M, C, edge, white, Ind, Adj[maxn], P[maxn], A[maxn];
vector<int> V[maxn];
queue<int> Q;

void Edg()
{
	int i, u;
	edge = 0;
	for (i = 0; i < C; i++)
	{
		u = A[i];
		if (color[u] == 1)
			edge += Adj[u];
	}
}

int BFS(int u)
{
	int i, v, c;
	while (!Q.empty())
		Q.pop();
	A[C++] = u;
	color[u] = 1;
	edge = 0;
	Q.push(u);
	Fg[u] = 1;
	white = 1;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		c = 1;
		if (color[u] == 1)
			c = 2;
		for (i = 0; i < V[u].size(); i++)
		{
			v = V[u][i];
			if (Fg[v] == 0)
			{
				color[v] = c;
				A[C++] = v;
				if (c == 1)
					white++;
				Q.push(v);
				Fg[v] = 1;
			}
			else if (color[v] == color[u])
				return 1;
		}
	}
	if (white != C / 2)
		return 1;
	if (C % 2 != 0)
		return 1;
	Edg();
	return 0;
}

int Special()
{
	if (!N && !M)
	{
		cout << "0\n\n";
		return 1;
	}
	if (!M)
	{
		cout << "Impossible\n";
		return 1;
	}
	return 0;
}

void Mark(int v)
{
	int u;
	u = P[v];
	if (u == -1)
		return;
	links[u][v]--;
	links[v][u]++;
	Mark(P[v]);
}

int Next(int n)
{
	int i, d, u;
	mark[n] = 1;
	for (i = 0; i < V[n].size(); i++)
	{
		u = V[n][i];
		if (mark[u] == 1)
			continue;
		if (links[n][u] == 0)
			continue;
		P[u] = n;
		if (color[u] == 2 && taken[u] == 0)
		{
			taken[u] = 1;
			Mark(u);
			return 1;
		}
		d = Next(u);
		if (d)
			return 1;
	}
	return 0;
}

int Greedy()
{
	int i, d = 0, j, u;
	for (i = 0; i < C; i++)
	{
		u = A[i];
		if (color[u] == 2)
			continue;
		for (j = 0; j < V[u].size(); j++)
		{
			d = V[u][j];
			links[d][u] = 0;
		}
	}
	for (i = 0; i < C; i++)
	{
		u = A[i];
		if (color[u] == 2)
			continue;
		P[u] = -1;
		for (j = 0; j < C; j++)
			mark[A[j]] = 0;
		d = Next(u);
		if (d == 0)
			return 1;
	}
	return 0;
}

void Cal()
{
	int i, d;
	if (Special())
		return;
	for (i = 1; i <= N; i++)
	{
		if (Fg[i] == 0)
		{
			C = 0;
			d = BFS(i);
			if (d)
			{
				cout << "Impossible\n";
				return;
			}
			if (Greedy())
			{
				cout << "Impossible\n";
				return;
			}
		}
	}
	cout << N / 2 << endl
			 << "1";
	for (i = 2; i <= N; i++)
		if (color[i] == 1)
			cout << " " << i;
	cout << endl;
}

void Free()
{
	int i, j, u;
	for (i = 1; i <= N; i++)
	{
		Fg[i] = color[i] = 0;
		for (j = 0; j < V[i].size(); j++)
		{
			u = V[i][j];
			links[i][u] = 0;
		}
		V[i].clear();
		Adj[i] = 0;
		taken[i] = 0;
	}
}

int main()
{
	int ks, u, v, i, k = 1;
	cin >> ks;
	while (ks--)
	{
		cin >> N >> M;
		cout << "Case #" << k++ << ": ";
		for (i = 0; i < M; i++)
		{
			cin >> u >> v;
			V[u].push_back(v);
			V[v].push_back(u);
			Adj[v]++;
			Adj[u]++;
			links[u][v] = links[v][u] = 1;
		}
		if (N % 2)
		{
			Free();
			cout << "Impossible\n";
			continue;
		}
		Cal();
		Free();
	}
	return 0;
}
