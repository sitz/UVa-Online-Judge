#include <bits/stdc++.h>

using namespace std;

#define maxn 20
#define INF 10000000
#define MIN(a, b) (a > b ? b : a)

int Cost[maxn][maxn], N, E, edge;
int Deg[maxn], mincost, totalcost;
struct ss
{
	int cost;
	int u, v;
};
ss Edge[250];
char Fg[maxn];

int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return x->cost - y->cost;
}

void Set()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			Cost[i][j] = Cost[j][i] = INF;
		}
		Cost[i][i] = Deg[i] = 0;
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
				Cost[i][j] = MIN(Cost[i][j], Cost[i][k] + Cost[k][j]);
			}
		}
	}
}

void Make_pair()
{
	int i, j;
	edge = 0;
	for (i = 1; i < N; i++)
	{
		if (Deg[i] % 2 == 0)
		{
			continue;
		}
		for (j = i + 1; j <= N; j++)
		{
			if (Deg[j] % 2 == 0)
			{
				continue;
			}
			Edge[edge].u = i;
			Edge[edge].v = j;
			Edge[edge++].cost = Cost[i][j];
		}
	}
}

int H(int ind, int level, int terget)
{
	int i, k = 0, j = 0;
	for (i = ind + 1; j < (terget - level); i++, j++)
	{
		k += Edge[i].cost;
	}
	return k;
}

void Recur(int n, int level, int terget, int cost)
{
	int i;
	if (cost >= mincost)
	{
		return;
	}
	if (level == terget)
	{
		if (cost < mincost)
		{
			mincost = cost;
		}
		return;
	}
	if (cost + H(n, level, terget) >= mincost)
	{
		return;
	}
	Fg[Edge[n].u] = Fg[Edge[n].v] = 1;
	for (i = n + 1; i < edge; i++)
	{
		if (Fg[Edge[i].u] || Fg[Edge[i].v])
		{
			continue;
		}
		if ((edge - i) < (terget - level))
		{
			break;
		}
		Recur(i, level + 1, terget, cost + Edge[i].cost);
	}
	Fg[Edge[n].u] = Fg[Edge[n].v] = 0;
}

void Cal()
{
	int i, k = 0;
	for (i = 1; i <= N; i++)
	{
		if (Deg[i] % 2)
		{
			k++;
		}
	}
	if (k == 0)
	{
		cout << totalcost << endl;
		return;
	}
	Floyd();
	Make_pair();
	if (edge == 1)
	{
		cout << Edge[0].cost + totalcost << endl;
		return;
	}
	qsort(Edge, edge, sizeof(ss), com);
	mincost = 99999999;
	for (i = 0; i + 1 < edge; i++)
	{
		Recur(i, 1, k / 2, Edge[i].cost);
	}
	cout << mincost + totalcost << endl;
}

int main()
{
	int i, u, v, c;
	while (cin >> N && N)
	{
		Set();
		cin >> E;
		totalcost = 0;
		for (i = 0; i < E; i++)
		{
			cin >> u >> v >> c;
			totalcost += c;
			if (Cost[u][v] > c)
				Cost[u][v] = Cost[v][u] = c;
			Deg[u]++;
			Deg[v]++;
		}
		Cal();
	}
	return 0;
}
