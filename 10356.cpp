#include <bits/stdc++.h>

using namespace std;

#define MAXN 502
#define MAX MAXN * 3
#define INF 21474836

struct ss
{
	int A[MAXN];
	int ind;
	int Odd, Even;
	char C;
} link[MAXN];
int Q[MAX], qh, qt, List[MAXN][MAXN], N, M;
void Ini()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		link[i].Odd = link[i].Even = INF;
		link[i].ind = 0;
		link[i].C = 'w';
		for (j = i + 1; j < N; j++)
		{
			List[i][j] = List[j][i] = 0;
		}
	}
}
void Push(int n)
{
	Q[qh++] = n;
	qh %= MAX;
}
int Pop()
{
	int n;
	n = Q[qt++];
	qt %= MAX;
	return n;
}
void BFS(int des)
{
	int i, k, n, ind, c;
	int Od, Ev, f;
	qh = qt = 0;
	link[0].Odd = INF;
	link[0].Even = 0;
	Push(0);
	while (qt != qh)
	{
		n = Pop();
		ind = link[n].ind;
		link[n].C = 'w';
		for (i = 0; i < ind; i++)
		{
			f = 0;
			k = link[n].A[i];
			c = List[n][k];
			Od = link[n].Even + c;
			Ev = link[n].Odd + c;
			if (link[k].Even > Ev)
			{
				link[k].Even = Ev;
				f = 1;
			}
			if (link[k].Odd > Od)
			{
				link[k].Odd = Od;
				f = 1;
			}
			if (f)
			{
				link[k].C = 'r';
				Push(k);
			}
		}
	}
}
void Cal()
{
	BFS(N - 1);
	if (link[N - 1].Even < INF)
	{
		printf("%d\n", link[N - 1].Even);
	}
	else
	{
		printf("?\n");
	}
}
int main()
{
	int i, u, v, c, ind1, ind2, st = 1;
	while (scanf("%d%d", &N, &M) == 2)
	{
		Ini();
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			ind1 = link[u].ind;
			ind2 = link[v].ind;
			if (List[u][v] || List[v][u])
			{
				if (List[u][v] > c)
				{
					List[u][v] = List[v][u] = c;
				}
				continue;
			}
			link[u].A[ind1] = v;
			link[v].A[ind2] = u;
			List[u][v] = List[v][u] = c;
			link[u].ind++;
			link[v].ind++;
		}
		printf("Set #%d\n", st++);
		Cal();
	}
	return 0;
}
