#include <bits/stdc++.h>

using namespace std;

#define maxn 40

int N, M, K, Cost[maxn][maxn], P[maxn];
char T[][4] = {"XXL", "XL", "L", "M", "S", "XS"};
vector<int> Link[maxn];
queue<int> Q;
char C[maxn];

int Find(char ss[])
{
	int i;
	for (i = 0; i < 6; i++)
		if (!strcmp(T[i], ss))
			return i + 1;
	return i;
}

void MakeLink()
{
	int i, n;
	K = M + 6 + 1;
	n = N / 6;
	for (i = M + 1; i < K; i++)
	{
		Link[i].push_back(K);
		Cost[i][K] = n;
	}
	for (i = 1; i <= M; i++)
	{
		Link[0].push_back(i);
		Cost[0][i] = 1;
	}
}

void Mark(int v)
{
	int u;
	if (v == 0)
		return;
	u = P[v];
	Cost[u][v]--;
	Cost[v][u]++;
	Mark(P[v]);
}

int BFS()
{
	int u, v, i;
	Q.push(0);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (i = 0; i < Link[u].size(); i++)
		{
			v = Link[u][i];
			if (Cost[u][v] == 0 || C[v])
				continue;
			C[v] = 1;
			P[v] = u;
			if (v == K)
			{
				Mark(v);
				return 1;
			}
			Q.push(v);
		}
	}
	return 0;
}

void Cal()
{
	int i, d, j;
	MakeLink();
	for (i = 1; i <= M; i++)
	{
		d = BFS();
		if (d == 0)
		{
			cout << "NO\n";
			return;
		}
		for (j = 0; j <= K; j++)
			C[j] = 0;
		while (!Q.empty())
			Q.pop();
	}
	cout << "YES\n";
}

int main()
{
	int ks, i, n, m;
	char ss[12], xx[12];
	cin >> ks;
	while (ks--)
	{
		cin >> N >> M;
		for (i = 1; i <= M; i++)
		{
			cin >> xx >> ss;
			n = Find(xx) + M;
			m = Find(ss) + M;
			Link[i].push_back(n);
			Link[i].push_back(m);
			Link[n].push_back(i);
			Link[m].push_back(i);
			Cost[i][n] = 1;
			Cost[i][m] = 1;
		}
		Cal();
		while (!Q.empty())
			Q.pop();
		for (i = 0; i <= K; i++)
		{
			C[i] = 0;
			Link[i].clear();
		}
	}
	return 0;
}
