#include <bits/stdc++.h>

using namespace std;

/*
10702
*/
#define MAXN 102

int End[MAXN];
int C, S, E, T;
struct qq
{
	int n, tour;
} xx;
queue<qq> Q;
struct ct
{
	char f;
	int cost;
} taka[MAXN][1002];
struct ss
{
	int list[MAXN];
	int Ad[MAXN];
	int ind;
} node[MAXN];
void BFS()
{
	int i, nw, n, tour, cost;
	qq temp, xyz;
	temp.n = S;
	temp.tour = 0;
	Q.push(temp);
	while (!Q.empty())
	{
		xyz = Q.front();
		Q.pop();
		tour = xyz.tour + 1;
		n = xyz.n;
		taka[n][xyz.tour].f = 0;
		for (i = 0; i < node[n].ind; i++)
		{
			nw = node[n].Ad[i];
			if (taka[nw][tour].cost < taka[n][xyz.tour].cost + node[n].list[i])
			{
				taka[nw][tour].cost = taka[n][xyz.tour].cost + node[n].list[i];
				if (taka[nw][tour].f == 0 && tour != T)
				{
					taka[nw][tour].f = 1;
					temp.n = nw;
					temp.tour = tour;
					Q.push(temp);
				}
			}
		}
	}
}
void Cal()
{
	int i, min = 0, k;
	BFS();
	for (i = 0; i < E; i++)
	{
		k = End[i];
		if (taka[k][T].cost > min)
		{
			min = taka[k][T].cost;
		}
	}
	printf("%d\n", min);
	Q.empty();
	for (i = 1; i <= C; i++)
	{
		for (k = 1; k <= T; k++)
		{
			taka[i][k].f = taka[i][k].cost = 0;
		}
	}
}
int main()
{
	int i, j, k;
	while (scanf("%d%d%d%d", &C, &S, &E, &T) == 4)
	{
		if (!C && !S && !E && !T)
		{
			break;
		}
		for (i = 1; i <= C; i++)
		{
			node[i].ind = 0;
			for (j = 1; j <= C; j++)
			{
				scanf("%d", &k);
				if (k)
				{
					node[i].list[node[i].ind] = k;
					node[i].Ad[node[i].ind++] = j;
				}
			}
		}
		for (i = 0; i < E; i++)
		{
			scanf("%d", &End[i]);
		}
		Cal();
	}
	return 0;
}
