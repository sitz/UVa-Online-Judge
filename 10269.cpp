#include <bits/stdc++.h>

using namespace std;

#define maxn 101
#define INF 9999999
#define MIN(a, b) (a > b ? b : a)

int Cost[maxn][11], F[maxn][maxn], W[maxn][maxn];
int N, M, A, B, K, L, mincost;
vector<int> V[maxn];
queue<int> Q;

void Ini()
{
	int i, j;
	N = A + B;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			F[i][j] = W[i][j] = INF;
		}
		F[i][i] = W[i][i] = 0;
		for (j = 0; j <= K; j++)
		{
			Cost[i][j] = INF;
		}
	}
	for (j = 0; j <= K; j++)
	{
		Cost[1][j] = 0;
	}
}

void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				W[i][j] = MIN(W[i][j], W[i][k] + W[k][j]);
				if (k <= A)
				{
					F[i][j] = MIN(F[i][j], F[i][k] + F[k][j]);
				}
			}
		}
	}
}

void BFS()
{
	int i, u, v, w, d, g, mm;
	Q.push(1);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (v = 1; v <= N; v++)
		{
			if (v == u)
			{
				continue;
			}
			g = 0;
			mm = INF;
			for (i = 0; i <= K; i++)
			{
				d = Cost[u][i];
				if (d >= mincost)
				{
					continue;
				}
				w = d + W[u][v];
				if (w < mincost && Cost[v][i] > w && w < mm)
				{
					Cost[v][i] = w;
					g = 1;
					mm = w;
					if (v == N)
					{
						mincost = w;
					}
				}
				if (i == K || F[u][v] > L)
				{
					continue;
				}
				if (d < mincost && Cost[v][i + 1] > d && mm > d)
				{
					Cost[v][i + 1] = d;
					g = 1;
					mm = d;
					if (v == N)
					{
						mincost = d;
					}
				}
			}
			if (g && v < N)
			{
				Q.push(v);
			}
		}
	}
}

void Cal()
{
	Floyd();
	mincost = W[1][N];
	if (F[1][N] < mincost)
	{
		mincost = F[1][N];
	}
	BFS();
	cout << mincost << endl;
}

int main()
{
	int ks, i, u, v, c;
	cin >> ks;
	while (ks--)
	{
		cin >> A >> B >> M >> L >> K;
		Ini();
		for (i = 1; i <= M; i++)
		{
			cin >> u >> v >> c;
			F[u][v] = F[v][u] = c;
			W[u][v] = W[v][u] = c;
		}
		Cal();
	}
	return 0;
}
