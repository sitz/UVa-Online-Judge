#include <bits/stdc++.h>

using namespace std;

/*
10557
XYZZY
*/
#define MAXN 10005
#define INF 1000000000
struct Vertex
{
	int Fixed;
	int Energy;
};
struct ss
{
	int u, v;
} E[MAXN];
Vertex V[102];
int Ind, N;
void ReadCase()
{
	int i, v, eng, n;
	Ind = 0;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &eng);
		V[i].Fixed = -eng;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &v);
			E[Ind].u = i;
			E[Ind++].v = v;
		}
	}
	V[1].Fixed = 0;
	V[N].Fixed = 0;
}
void Bellman_Ford()
{
	int i, j, u, v, d;
	for (i = 2; i <= N; i++)
	{
		V[i].Energy = INF;
	}
	V[1].Energy = -100;
	for (i = 1; i <= 19900; i++)
	{
		for (j = 0; j < Ind; j++)
		{
			u = E[j].u;
			v = E[j].v;
			if (V[u].Energy >= 0)
			{
				continue;
			}
			d = V[u].Energy + V[v].Fixed;
			if (d < V[v].Energy)
			{
				V[v].Energy = d;
			}
			if (V[N].Energy < INF)
			{
				return;
			}
		}
	}
}
void Cal()
{
	Bellman_Ford();
	if (V[N].Energy < INF)
	{
		printf("winnable\n");
	}
	else
	{
		printf("hopeless\n");
	}
}
int main()
{
	while (scanf("%d", &N) == 1)
	{
		if (N < 0)
		{
			break;
		}
		ReadCase();
		Cal();
	}
	return 0;
}
