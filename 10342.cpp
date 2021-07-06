#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define INF 1000000
#define MIN(a, b) (a > b ? b : a)

int N, E;

struct ss
{
	int ini;
	int best;
	int sec;
} Cost[MAXN][MAXN];
void BestIni()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Cost[i][j].best = INF;
			Cost[i][j].ini = INF;
		}
		Cost[i][i].best = 0;
		Cost[i][i].ini = 0;
	}
}
void FindBest()
{
	int i, j, k;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				Cost[i][j].best =
						MIN(Cost[i][j].best, Cost[i][k].best + Cost[k][j].best);
			}
		}
	}
}
void SecIni()
{
	int i, j, min;
	for (i = 0; i < N; i++)
	{
		min = INF;
		for (j = 0; j < N; j++)
		{
			if (i != j)
			{
				min = MIN(min, Cost[i][j].best);
			}
			Cost[i][j].sec = MIN(Cost[i][j].ini, Cost[i][j].best * 3);
			if (Cost[i][j].sec == Cost[i][j].best)
			{
				Cost[i][j].sec = Cost[i][j].best * 3;
			}
		}
		Cost[i][i].sec = min * 2;
	}
}
void FindSecond()
{
	int i, j, k, secbest;
	int bb, bs, sb, ss;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				bb = Cost[i][k].best + Cost[k][j].best;
				bs = Cost[i][k].best + Cost[k][j].sec;
				sb = Cost[i][k].sec + Cost[k][j].best;
				ss = Cost[i][k].sec + Cost[k][j].sec;
				secbest = MIN(bs, MIN(sb, ss));
				if (bb != Cost[i][j].best)
				{
					secbest = MIN(secbest, bb);
				}
				Cost[i][j].sec = MIN(Cost[i][j].sec, secbest);
			}
		}
	}
}
void Cal()
{
	int Q, u, v;
	scanf("%d", &Q);
	FindBest();
	SecIni();
	FindSecond();
	while (Q--)
	{
		scanf("%d%d", &u, &v);
		Cost[u][v].sec < INF ? printf("%d\n", Cost[u][v].sec) : printf("?\n");
	}
}

int main()
{
	int i, u, v, c, Set = 1;
	while (scanf("%d%d", &N, &E) == 2)
	{
		BestIni();
		for (i = 0; i < E; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			Cost[u][v].best = Cost[v][u].best = c;
			Cost[u][v].ini = Cost[v][u].ini = c;
		}
		printf("Set #%d\n", Set++);
		Cal();
	}
	return 0;
}
