#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define INF 2147483647
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

struct ss
{
	int u, v;
	double temp, dis;
};
ss Edge[MAXN * 100];
int N, E, S, T, P[MAXN][MAXN];
double D[MAXN][MAXN], Tp[MAXN][MAXN];

void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			D[i][j] = Tp[i][j] = INF;
			P[i][j] = i;
		}
		D[i][i] = Tp[i][i] = 0;
	}
}
void ReadCase()
{
	int i, u, v;
	double d, t;
	scanf("%d%d", &S, &T);
	for (i = 0; i < E; i++)
	{
		scanf("%d%d%lf%lf", &u, &v, &t, &d);
		Edge[i].u = u;
		Edge[i].v = v;
		Edge[i].dis = d;
		Edge[i].temp = t;
		if (Tp[u][v] > t)
		{
			Tp[u][v] = t;
			Tp[v][u] = t;
		}
	}
}
void GetTemp()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				Tp[i][j] = min(Tp[i][j], max(Tp[i][k], Tp[k][j]));
}
void GetDis(double lim)
{
	int i, j, k;
	double dis;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				dis = D[i][k] + D[k][j];
				if (D[i][j] > dis)
				{
					D[i][j] = dis;
					P[i][j] = P[k][j];
				}
			}
}
void Set(double lim)
{
	int i, u, v;
	for (i = 0; i < E; i++)
	{
		u = Edge[i].u;
		v = Edge[i].v;
		if (D[u][v] > Edge[i].dis && Edge[i].temp <= lim)
			D[u][v] = D[v][u] = Edge[i].dis;
	}
}
void Print(int u, int v)
{
	if (u == v)
		printf("%d", v);
	else
	{
		Print(u, P[u][v]);
		printf(" %d", v);
	}
}
void Cal()
{
	double Limit;
	GetTemp();
	Limit = Tp[S][T];
	Set(Limit);
	GetDis(Limit);
	Print(S, T);
	printf("\n");
	printf("%.1lf %.1lf\n", D[S][T], Tp[S][T]);
}

int main()
{
	while (scanf("%d%d", &N, &E) == 2)
	{
		Ini();
		ReadCase();
		Cal();
	}
	return 0;
}
