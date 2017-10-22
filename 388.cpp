#include <bits/stdc++.h>

using namespace std;

#define N 27
#define INF 100
#define EARTH 26

int dist[N][N];
double val[N];

void floyd_warshall(void)
{
	register int i, j, k;
	for (k = 0; k < N; ++k)
	{
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				int dist_ikj = dist[i][k] + dist[k][j];
				if (dist_ikj < dist[i][j])
				{
					dist[i][j] = dist_ikj;
				}
			}
		}
	}
}

void add_edge(char A, char B)
{
	int i = (A == '*') ? EARTH : A - 'A';
	int j = (B == '*') ? EARTH : B - 'A';
	dist[i][j] = 1;
	dist[j][i] = 1;
}

void init()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		val[i] = 0.0f;
	}
}

double import_val(int planet)
{
	if (dist[EARTH][planet] < INF)
	{
		return pow(0.95, dist[EARTH][planet] - 1) * val[planet];
	}
	else
	{
		return 0.0;
	}
}

void find_best()
{
	double best = 0.0;
	int i, planet = 0;
	for (i = 0; i < EARTH; ++i)
	{
		double v = import_val(i);
		if (v > best)
		{
			best = v;
			planet = i;
		}
	}
	printf("Import from %c\n", planet + 'A');
}

int main()
{
	int i, j, planets;
	while (scanf("%d\n", &planets) == 1)
	{
		init();
		for (i = 0; i < planets; ++i)
		{
			double v;
			char p, neighbor[N];
			scanf("%c %lf %s\n", &p, &v, neighbor);
			val[p - 'A'] = v;
			for (j = 0; j < (int)strlen(neighbor); ++j)
			{
				add_edge(p, neighbor[j]);
			}
		}
		floyd_warshall();
		find_best();
	}
	return 0;
}
